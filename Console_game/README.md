
# Console game map manual



## map files are located in "data" folder next to folder where execution file loacted.    
    
    
## map file format tags    
### every tags MUST NOT include enter or space.    
    
- rule    
  write integer next to tag to inform how many rules will be listed next to this tag    
  - speed_score_show    
    write "true" or 1 to show speed score on game over screen    
    write "false" or 0 to hide speed score on game over screen    
  - time_score_show    
    write "true" or 1 to show time score on game over screen    
    write "false" or 0 to hide time score on game over screen    
  - break_score_show    
    write "true" or 1 to show break score on game over screen    
    write "false" or 0 to hide break score on game over screen    
      
    
- map    
  write 120 x 30 number of integers next to tag to build map.    
  (check map tile numbers below)    
    
- ecel    
  write float number next to tag to inform ecelation power of character    
  default value is 100    
    
- decel    
  write float number next to tag to inform decelation power of character    
  default value is 100    
    
- time_limit    
  write float number next to tag to inform how many second game will last    
  e.g. 60 is 60 second    
  e.g. 30.5 is 30.5 second    
    
- collision_accuracy    
  write integer next to tag to inform how many time game will check collision per frame    
  increase this value if character move is not legal    
  decrease this value game is laggy    
  default value is 100
    
    
    
    
## map file tile number    
### wite these number after map tag to construct map    
    
- 0 : blank    
  do nothing    
    
- 1 : wall    
  reflect character with half-speed    
    
- 2 : breakable wall    
  same with wall, but change into blank when collision happen    
    
- 3 : ice    
  speed up character when character is on this tile    
    
- 4 : lava    
  trigger game over    
  can be used for dangerous-point and goal-point in cases
    
- 5 : slime
  reflect character without speed reduction    
    