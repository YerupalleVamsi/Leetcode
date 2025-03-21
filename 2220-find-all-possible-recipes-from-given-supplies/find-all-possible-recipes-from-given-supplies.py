class Solution:
    def findAllRecipes(self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]) -> List[str]:
        supplies = set(supplies)
        possible_recipes = set()
        remaining_recipes = set(recipes)

        while True:
            new_recipe_found = False
            for i in range(len(recipes)):
                if recipes[i] in possible_recipes:
                    continue
                if all(item in supplies for item in ingredients[i]):
                    supplies.add(recipes[i])
                    possible_recipes.add(recipes[i])
                    remaining_recipes.remove(recipes[i])
                    new_recipe_found = True
            if not new_recipe_found:
                break

        return list(possible_recipes)
        