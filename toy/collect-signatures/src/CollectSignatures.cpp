#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
/*
Problem Introduction (from Coursera):

	You are responsible for collecting signatures from all tenants of a certain building.
	For each tenant, you know a period of time when he or she is at home.
	You would like to collect all signatures by visiting the building as few times as
	possible.
	The mathematical model for this problem is the following. You are given a set
	of segments on a line and your goal is to mark as few points on a line as possible
	so that each segment contains at least one marked point.
*/

using std::vector;
using namespace std;

struct Segment {
  int start, end;
};

bool sort_ascending(Segment x, Segment y) {
    return (x.start < y.start);
}

void print_vector(const vector<Segment> &segments) {
	for (size_t i = 0; i < segments.size(); i++) cout << "[" << segments[i].start << " ; " << segments[i].end << "]" << endl;
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  vector<Segment>::iterator current_segment = segments.begin(); // we start from the first segment (call it 'X') on a sorted list
  vector<Segment>::iterator advancing_pointer = segments.begin(); // ... and obtain an iterator for traversing all segments which begin earlier than 'X' ends
  while (current_segment != segments.end()) {
	  int current_end = current_segment->end; // the output point
	  int lookahead_until = current_segment->end; // we will only consider segments which start earlier than the current segment finishes
	  while (advancing_pointer != segments.end() && advancing_pointer->start <= lookahead_until) {
		  // cout << "Now pointing at [" << advancing_pointer->start << " ; " << advancing_pointer -> end << "]";
		  if (advancing_pointer->end < current_end) current_end = advancing_pointer->end; // choose the point which finishes earliest
		  advancing_pointer++; // move to the next sorted segment
	  }
	  points.push_back(current_end);
	  current_segment = advancing_pointer;
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  sort(segments.begin(), segments.end(), sort_ascending);
  // print_vector(segments);
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
