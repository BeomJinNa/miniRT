import random

# Constants
NUM_CYLINDERS = 300
MIN_HEIGHT = 30
MAX_HEIGHT = 200

# Generate cylinders
cylinders = []
for _ in range(NUM_CYLINDERS):
    x = random.uniform(-100, 1200)
    y = random.uniform(-250, 250)
    z = random.uniform(-250, 250)
    height = random.uniform(MIN_HEIGHT, MAX_HEIGHT)
    diameter = random.uniform(0.2 * height, 0.5 * height)
    r = random.randint(0, 255)
    g = random.randint(0, 255)
    b = random.randint(0, 255)
    cylinders.append(((x, y, z), diameter, height, (r, g, b)))

# Print in .rt format
print("A 0.0005  255,255,255")
print("C -0.0,-0.0,-0.0  1.0,0.0,0.0  70")
print("L 0.0,0.0,-200.0 0.5  255,255,255")
for cylinder in cylinders:
    position, diameter, height, color = cylinder
    print(f"cy {position[0]},{position[1]},{position[2]}  1.0,0.0,0.0 {diameter / 2} {height}  {color[0]},{color[1]},{color[2]}")
