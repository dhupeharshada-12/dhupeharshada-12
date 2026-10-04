print("===== RECIPE INGREDIENT SCALER =====")

ingredients = {}

n = int(input("Enter number of ingredients: "))

for i in range(n):
    name = input(f"Enter ingredient {i + 1}: ")
    quantity = float(input(f"Enter quantity of {name}: "))
    ingredients[name] = quantity

original_servings = int(input("Enter original servings: "))
new_servings = int(input("Enter required servings: "))

factor = new_servings / original_servings

print("\n--- Updated Recipe ---")

for name, quantity in ingredients.items():
    new_quantity = quantity * factor
    print(name, ":", round(new_quantity, 2))

print("\nRecipe adjusted for", new_servings, "servings.")
