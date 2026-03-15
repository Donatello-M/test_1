#include <stdio.h>

int main() {
    int rect1_left, rect1_bottom, rect1_right, rect1_top;
    int rect2_left, rect2_bottom, rect2_right, rect2_top;

    scanf("%d %d %d %d", &rect1_left, &rect1_bottom, &rect1_right, &rect1_top);
    scanf("%d %d %d %d", &rect2_left, &rect2_bottom, &rect2_right, &rect2_top);

    int rect1_area = (rect1_right - rect1_left) * (rect1_top - rect1_bottom);
    int rect2_area = (rect2_right - rect2_left) * (rect2_top - rect2_bottom);

    int overlap_left = rect1_left > rect2_left ? rect1_left : rect2_left;
    int overlap_right = rect1_right < rect2_right ? rect1_right : rect2_right;
    int overlap_bottom = rect1_bottom > rect2_bottom ? rect1_bottom : rect2_bottom;
    int overlap_top = rect1_top < rect2_top ? rect1_top : rect2_top;

    int overlap_area = 0;

    if (overlap_right > overlap_left && overlap_top > overlap_bottom) {
        overlap_area = (overlap_right - overlap_left) * (overlap_top - overlap_bottom);
    }

    int total_area = rect1_area + rect2_area - overlap_area;

    printf("%d\n", total_area);

    return 0;
}
