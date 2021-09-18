# Boxing Unboxing

- C#의 모든 타입은 `System.Object`에서 파생되었다.
  - 이는 곧 모든 타입이 `System.Object`의 인터페이스를 제공함을 뜻한다.
  
- C#의 타입은 크게 값과 참조로 나뉜다.
  - 참조타입은 인스턴스 시 동적 객체로 힙에 할당된다.
  - 값타입은 인스턴스 시 지역 객체로 스택에 할당된다.


- Boxing은 값 타입을 참조타입으로 전환하는 작업이고, Unboxing은 참조타입에서 값타입으로의 전환을 시도하는 것이다.
  - 값타입과 참조타입은 모두 `System.Object`의 서브타입이므로 이는 불가피하다.
  - 작업 시 많은 자원을 필요로 하므로 Generic으로 대체하는 것이 좋다.
  
``` C#
	int i = 123;
	// Boxing copies the value of i into object o.
	object o = i;
	//object o = (object)i;  // explicit boxing
```
![img](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/types/media/boxing-and-unboxing/boxing-operation-i-o-variables.gif)

``` C#
	int i = 123;      // a value type
	object o = i;     // boxing
	int j = (int)o;   // unboxing
```
![img](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/types/media/boxing-and-unboxing/unboxing-conversion-operation.gif)

- enum과 struct는 16byte 미만일 경우 값타입으로 취급된다.