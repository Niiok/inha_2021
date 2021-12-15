# Cleania's system

----

- In-Unity (MonoBehavior)
  - [UI_ItemContainer](#UI_ItemContainer)
    - observer(observer)
  - [UI_ItemController](#UI_ItemContainer)
    - proxy
  - [AbilityStatus]()
    - facade
  - [Status]()
    - adapter
  - [Equipable]  
    - observer(observer)
  
- Out-Unity
  - [SavedData]()
    - singleton
  - [ItemStorage]()
    - bridge, observer(subject)
  - [ItemInstance]()
    - factory, prototype
  - [ItemInstance_Equipment]()
  
----

### In-Unity
> Generated with Scene    
> Destroyed with Scene    
- Can not become whole-time system

#### UI_ItemContainer
> work as Inventory shown to players    
> observer(observer)    
- inspect ItemStorage
  - subscribe `ItemStorage` on `Start()`
  - unsubscribe `ItemStorage` on `OnDestroy()`

#### UI_ItemController
> Shown as Slotted Item in UI_ItemContainer    
> proxy    
- callback `UI_ItemContainer`'s function by Unity events

#### AbilityStatus
> 

#### Status
> 

#### Equipable
> observer(observer)    
- inspect ItemStorage_Equipment
  - subscribe `ItemStorage_Equipment` on `Start()`
  - unsubscribe `ItemStorage_Equipment` on `OnDestroy()`

----

### Out-Unity
> Generated with Application    
> Destroyed with Application    

#### SavedData

#### ItemStorage

#### ItemInstance

#### ItemInstance_Equipment