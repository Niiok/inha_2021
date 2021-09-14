# How to use Equipment class
   
## Enum
```
public enum Type
{
	MainWeapon,
	SubWeapon,
	Hat,
	Top,
	Pants,
	Gloves,
	Shoes,
	EnumTotal
}
```
   
## Fields

### `Type EquipmentType`
- returns type of equipment
- 장비 종류를 반환
> getter

### `Dictionary<Ability.Stat, float> StaticProperties`
- returns `_stats`(static properties)' copy
- you can get count of `_stats`' size with `StaticProperties.Count`
- you can use foreach with `StaticProperties`
- use `this[stat]` to change value
- 고정속성들을 반환
- `StaticProperties.Count`를 통해 고정속성의 개수 확인 가능
- foreach를 통해 모든 고정속성에 접근 가능
- 하지만 변환은 `this[stat]`만으로 가능
> getter only

### `Dictionary<Ability.Stat, float> DynamicProperties`
- returns `_enchants`(dynamic properties)' copy
- you can get count of `_enchants`' size with `DynamicProperties.Count`
- you can use foreach with `DynamicProperties`
- use `this[stat, enhance]` to change value
- 가변속성들을 반환
- `DynamicProperties.Count`를 통해 가변속성의 개수 확인 가능
- foreach를 통해 모든 가변속성에 접근 가능
- 하지만 변환은 `this[stat, enhance]`만으로 가능
> getter only
	
	
## Methods
	
### `float this[Ability.Stat]`
- getter : returns static property
> e.g.) hero_sword[Ability.Stat.Attack]
- setter : change static property
- put 0 to remove property
> e.g.) hero_sword[Ability.Stat.Attack] += 10;
    
### `float this[Ability.Stat, Ability.Enhance]`
- returns dynamic property
> e.g.) hero_sword[Ability.Stat.Attack, Ability.Enhance.Addition_Percent]
- setter : change dynamic property
- put 0 to remove property
> e.g.) hero_sword[Ability.Stat.Attack, Ability.Enhance.Addition_Percent] = 0.12;

### `List<String> StaticProperties_ToString()`
- returns strings explaining about static properies

### `List<String> DynamicProperties_ToString()`
- returns strings explaining about dynamic properies