# How to use AbilityStatus class
    
## Fields
    
### `float HP` & `float MP`
- returns current HP or MP
> getter
    


## Methods
	
### `float this[Ability.Stat]`
- returns total stat data after calculations
> e.g.) enemy2_status[Ability.Stat.Attack]

### `void FullHP(void)` & `void FullMP(void)`
- set HP or MP into maximum value
    
### `float AttackedBy(AbilityStatus, float)`
- reduce HP of `this`.
  - referenced by `param1`'s stats and `param2`    
    
### `bool ConsumeHP(float)` & `bool ConsumeMP(float)`
- try to use `param1` amount of HP or MP as resource
- reduce HP or MP if this function return true
    
### `float GetStat(Ability.Stat stat)`
- same with `float this[Ability.Stat]`
    