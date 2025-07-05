from typing import List


def sameFleet(target: int, frontCar, backCar):
    d1 = target - frontCar[0]
    d2 = target - backCar[0]
    v1 = frontCar[1]
    v2 = backCar[1]

    return d1 * v2 >= d2 * v1


class Solution:

    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        n = len(position)
        cars = []
        for i in range(n):
            cars.append([position[i], speed[i]])

        # Sort by position, furthest along cars first
        cars.sort(key=lambda x: x[0], reverse=True)

        fleets = [cars[0]]

        for i in range(1, n):
            if not sameFleet(target, fleets[-1], cars[i]):
                fleets.append(cars[i])

        return len(fleets)
