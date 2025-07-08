#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

// tree[k][0]: 노드의 값
// tree[k][1]: 왼쪽 자식 노드의 값 (없으면 -1)
// tree[k][2]: 오른쪽 자식 노드의 값 (없으면 -1)
int tree[10002][3];
int arr[10000];
// index[노드값] = tree 배열의 인덱스 (rcnt)
int index[1000001]; 
int rcnt; 
int inputIdx; 
int divide(int root_val, int search_start_idx, int search_end_idx) {
    for (int i = search_start_idx; i <= search_end_idx; i++) {
        if (arr[i] > root_val) {
            return i; // root_val보다 큰 첫 번째 값을 찾으면 해당 인덱스 반환
        }
    }
    return search_end_idx + 1; 
}

// current_root_arr_idx: 현재 서브트리의 루트 노드가 arr 배열에서 위치하는 인덱스
// current_subtree_end_arr_idx: 현재 서브트리에 속하는 요소들의 arr 배열 내 마지막 인덱스
void make(int current_root_arr_idx, int current_subtree_end_arr_idx) {
    // 재귀 호출의 기본 케이스: 현재 서브트리의 범위가 유효하지 않으면 (즉, 더 이상 노드를 만들 수 없으면) 반환
    if (current_root_arr_idx > current_subtree_end_arr_idx) {
        return;
    }

    // 현재 서브트리의 루트 노드 값
    int root_val = arr[current_root_arr_idx];

    // tree 배열에 현재 루트 노드의 값을 저장하고, 노드 값과 tree 배열 인덱스를 매핑
    tree[rcnt][0] = root_val;
    index[root_val] = rcnt;
    int current_node_tree_idx = rcnt; // 현재 노드의 tree 배열 내 인덱스 저장
    rcnt++; // 다음 노드를 위해 rcnt 증가

    // divide 함수를 사용하여 오른쪽 서브트리의 시작 인덱스를 arr 배열에서 찾음
    // 검색 범위는 현재 루트 다음 요소부터 현재 서브트리의 끝까지
    int right_subtree_start_arr_idx = divide(root_val, current_root_arr_idx + 1, current_subtree_end_arr_idx);

    int left_subtree_start_arr_idx = current_root_arr_idx + 1;
    int left_subtree_end_arr_idx = right_subtree_start_arr_idx - 1;

    int right_subtree_end_arr_idx = current_subtree_end_arr_idx;
    if (left_subtree_start_arr_idx <= left_subtree_end_arr_idx) {
        tree[current_node_tree_idx][1] = arr[left_subtree_start_arr_idx];
        make(left_subtree_start_arr_idx, left_subtree_end_arr_idx);
    } else {
        tree[current_node_tree_idx][1] = -1;
    }

    if (right_subtree_start_arr_idx <= right_subtree_end_arr_idx) {
        tree[current_node_tree_idx][2] = arr[right_subtree_start_arr_idx];
        make(right_subtree_start_arr_idx, right_subtree_end_arr_idx);
    } else {
        tree[current_node_tree_idx][2] = -1;
    }
}

// 이진 트리를 후위 순회하며 노드 값을 출력하는 함수
// node: 현재 방문할 노드의 값
void post_order(int node) {
    // 노드가 -1 (null)이면 반환
    if (node == -1) return;
    
    post_order(tree[index[node]][1]);
    post_order(tree[index[node]][2]);
    cout << node << "\n"; 
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int num;
    rcnt = 0;
    inputIdx = 0;
    
    // 파일의 끝(EOF)에 도달할 때까지 숫자를 읽어 arr 배열에 저장
    while (cin >> num) {
        arr[inputIdx++] = num;
    }
    
    make(0, inputIdx - 1);
    post_order(arr[0]);
    
    return 0;
}
