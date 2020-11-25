
#include "task_2.h"

int main() {
    s_data data;

    make_random_points(&data);
    remove_useless_points(&data);
    return 0;
}
