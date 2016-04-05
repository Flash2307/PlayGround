.PHONY: clean All

All:
	@echo "----------Building project:[ Snakeus - Debug ]----------"
	@cd "Snakeus" && "$(MAKE)" -f  "Snakeus.mk" && "$(MAKE)" -f  "Snakeus.mk" PostBuild
clean:
	@echo "----------Cleaning project:[ Snakeus - Debug ]----------"
	@cd "Snakeus" && "$(MAKE)" -f  "Snakeus.mk" clean
