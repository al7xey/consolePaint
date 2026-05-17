#include "drawing/QueueFillStrategy.h"

#include "Canvas.h"

#include <queue>
#include <utility>

void QueueFillStrategy::fill(Canvas& canvas, int startX, int startY, char symbol) const {
    const char target = canvas.getPixel(startX, startY);
    if (target == '\0' || target == symbol) {
        return;
    }

    std::queue<std::pair<int, int>> cells;
    cells.push({startX, startY});

    while (!cells.empty()) {
        const auto [x, y] = cells.front();
        cells.pop();

        if (canvas.getPixel(x, y) != target) {
            continue;
        }

        canvas.setPixel(x, y, symbol);
        cells.push({x + 1, y});
        cells.push({x - 1, y});
        cells.push({x, y + 1});
        cells.push({x, y - 1});
    }
}
