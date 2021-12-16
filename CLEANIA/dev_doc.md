# Cleania's system

----

- In-Unity (MonoBehavior)
  - [UI_ItemContainer](#UI_ItemContainer)
    - 옵저버(`ItemStroage` 구독)
	- 프록시(`ItemStorage`로)
  - [UI_ItemController](#UI_ItemController)
    - 프록시(`UI_ItemContainer`로)
  - [AbilityStatus](#AbilityStatus)
	- 퍼사드? (옵저버!)
  - [Status](#Status)
    - 어댑터(`StatusSO` => `AbilityStatus`)
  - [Equipable](#Equipable)
    - 옵저버(`ItemStorage` 구독)
	- 프록시(`ItemStorage`로)
	- 어댑터(`ItemInstance_Equipment`들 => `AbilityStatus`)
  
- Out-Unity
  - [SavedData](#SavedData)
    - 싱글톤
  - [ItemStorage](#ItemStorage)
    - 브릿지, 옵저버(발행자)
  - [ItemInstance](#ItemInstance)
    - 팩토리, 프로토타입
  - [ItemInstance_Equipment](#ItemInstance_Equipment)
	- .
  
----

## In-Unity
> 씬과 함께 생성    
> 씬과 함께 제거    
- 게임 전체의 시스템을 맡을 수는 없음

#### UI_ItemContainer
> 플레이어에게 노출되는 인벤토리    
- 옵저버 (`ItemStorage` 구독)
  - `ItemStorage`가 변경되면 `UI_ItemController`를 생성/제거
- 프록시(`ItemStorage`로)    
  - `this`에 대한 추가/삭제는 직접 실행하지 않고 구독한 `ItemStorage`로 전달
    - `UI_ItemController`가 주로 사용

#### UI_ItemController
> `UI_ItemContainer`의 아이템 슬롯으로 나타남    
- 프록시(`UI_ItemContainer`로)    
  - 유니티 이벤트에 따라 `UI_ItemContainer`의 함수를 콜백

#### AbilityStatus
> 공격받고 공격할 수 있는 객체의 스탯 수치를 산출    
> HP와 MP의 저장, 관리    
> `this.AttackedBy()`를 통한 데미지 계산    
- 퍼사드?
  - `Equipable`, `Status`, `Buffable`의 값을 모아 표면적인 스탯을 저장, 반영
    - get마다 매번 계산하기보단 **옵저버**로 변경하여 성능 향상 가능해보임

#### Status
> 레벨에 따른 기초 스텟 산출    
- 어댑터
  - 레벨이 오름에 따른 스텟 변화 규칙이 다르기에 적합한 방식으로 테이블을 읽어줌
    - `Status_ArithmeticProgress`, `Status_Table`

#### Equipable
> 유닛의 착용중인 장비를 저장    
> 착용중인 장비의 스탯을 산출
- 옵저버 (`ItemStorage` 구독)    
  - `ItemStorage`가 변경되면 `ItemInstance_Equipment`를 가져와서 수치 반영
- 프록시 (`ItemStorage`로)
  - `this`에 대한 추가/삭제는 직접 실행하지 않고 구독한 `ItemStorage`로 전달
- 어댑터 (`ItemInstance_Equipment`들 => `AbilityStatus`)
  - 여러 `ItemInstance_Equipment`의 스탯 반영을 한차례 계산하여 반영할 수 있도록 산출, 저장


----

## Out-Unity
> 어플리케이션과 함께 생성    
> 어플리케이션과 함께 제거    

#### SavedData

#### ItemStorage

#### ItemInstance

#### ItemInstance_Equipment