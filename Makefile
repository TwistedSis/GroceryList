.PHONY: clean All

All:
	@echo "----------Building project:[ GroceryListFirstDraft - Debug ]----------"
	@cd "GroceryListFirstDraft" && "$(MAKE)" -f  "GroceryListFirstDraft.mk"
clean:
	@echo "----------Cleaning project:[ GroceryListFirstDraft - Debug ]----------"
	@cd "GroceryListFirstDraft" && "$(MAKE)" -f  "GroceryListFirstDraft.mk" clean
