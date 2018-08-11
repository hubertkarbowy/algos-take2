#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b)) 

struct item {
    int value;
    int weight;
    float value_by_weight;
    struct item* next;
    struct item* prev;
};

void print_help_and_exit(char** argv) {
    printf("Usage: %s -p path_to_file\n", argv[0]);
    exit(-1);
}

void print_error_and_exit(const char* msg) {
    printf("%s", msg);
    exit(-1);
}

void print_list(struct item *list) {
    struct item* item = list;
    while (item != NULL) {
        printf("Item v=%d, w=%d, unit value = %f\n", item->value, item->weight, item->value_by_weight);
        item = item->next;
    }
}

void add_item_to_list(struct item** list, struct item* new_item) {
    if (*list == NULL) {
        *list = new_item;
        return;
    }
    (*list)->prev = new_item;
    new_item->next = *list;
    *list = new_item;
}

void remove_item_from_list(struct item** list, struct item* item) {
    if (item==NULL || *list == NULL) return; // not good practice
    if (item->prev == NULL) {  // if this is the first element...
     if (item->next == NULL) { //   ... then check if it isn't also the last one
        *list = NULL;          //   ... and if so, then make the list empty.
     }
     else {
        *list = item->next;    //   Otherwise, make the next element current head,
        (*list)->prev=NULL;    //   and set its prev to NULL
     }
    }
    else {
        if (item->next == NULL) { // last item
            item->prev->next=NULL;
        }
        else {                    // middle element;
            item->next->prev = item->prev;
            item->prev->next = item->next;
        }
    }
    free(item);
}

struct item* find_max_item(struct item* list) {
    float max_value = -1.0;
    struct item *selected;
    if (list==NULL) return NULL;
    struct item *next = list;
    while (next != NULL) {
       if (next->value_by_weight > max_value) {
          selected = next;
          max_value = next->value_by_weight;
       } 
       next = next->next;
    }
    return selected;
}

int main(int argc, char** argv) {
    int c;
    int number_of_items, weight, value, counter, tmp;
    float capacity, max_loot;
    char* path;
    FILE* fh;
    struct item *list_of_items, *new_item;
    
    if (argc==1) print_help_and_exit(argv);
    while ((c = getopt(argc, argv, "p:")) != -1) {
        if (c=='p') {
            printf("Loading fractional knapsack data from! %s\n", optarg);
            path=strdup(optarg);
        }
        if (c=='?') print_help_and_exit(argv);
    }
    if (access(path, F_OK | R_OK) != 0) print_error_and_exit("Cannot open file!\n");
    fh=fopen(path, "r");
    
    printf("OK\n");
    fscanf(fh, "%d", &number_of_items);
    fscanf(fh, "%f", &capacity);
    printf("The number of items is %d and capacity is %f\n", number_of_items, capacity);

    counter = 0;
    list_of_items = NULL;
    while ( (fscanf(fh, "%d", &tmp)) != EOF ) {
        if (counter==0) {
            value = tmp;
            counter++;
            continue;
        }
        if (counter==1) {
            weight = tmp;
            new_item = malloc(sizeof(struct item));
            new_item->value = value;
            new_item->weight = weight;
            new_item->value_by_weight = (float)value/weight;
            add_item_to_list(&list_of_items, new_item);
            counter = 0;
            printf("Adding v=%d, w=%d\n", value, weight);
            if (list_of_items == NULL) printf("List is null\n");
        }
    }

    print_list(list_of_items);
    max_loot = 0.0;
    while (capacity>0 && list_of_items != NULL) {
        struct item *most_valuable_now = find_max_item(list_of_items);
        float add_amount;
        if (most_valuable_now->weight < capacity) add_amount = 1.0;
        else add_amount = (float)capacity / most_valuable_now->weight;
        printf("Adding %f of the item (v=%d, w=%d, uv=%f)\n", add_amount, most_valuable_now->value, most_valuable_now->weight, most_valuable_now->value_by_weight);
        capacity = capacity - add_amount*most_valuable_now->weight;
        max_loot = max_loot + (add_amount * most_valuable_now->value);
        remove_item_from_list(&list_of_items, most_valuable_now);
        // printf ("======== REMAINING ITEMS: ======\n");
        // print_list(list_of_items);
        // printf ("================================\n");
    }

    printf("Max loot value is %f\n", max_loot);

    fclose(fh);
    free(path);
    return 0;
}
