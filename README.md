## Описание
Прототип онлайн-аптеки. В схеме аптеки есть аккаунты и товары. У товаров есть свои типы (товары по рецепту, обычные товары и т.д.). У аккаунтов тоже есть свои типы - доктор, покупатель, продавец и так далее. То, какими товарами может владеть аккаунт, регулируется политиками валидации. Код онлайн-аптеки был спроектирован для удобного добавления новых типов товаров, аккаунтов и политик валидации через систему абстрактных фабрик. Описание существующих политик, товаров и аккаунов находится в pharmacy_er.png.

### Общая схема работы 
Для создания нужного типа билдера аккаунта вызывается AccountCreatorsManager, с помощью него создается аккаунт нужного типа. Далее то же самое происходит с товарами. Аккаунт и массив товаров кидаются в валидатор Validator, который возвращает массив состояний. По исключениям и состояниям формируется ответ.

### Описание классов для работы с аккаунтами
#### Account
Абстрактный класс для аккаунтов, от которого нужно наследоваться. Имеет два метода - GetType() и GetData().
#### AccountCreator
Абстрактный класс для создания аккаунтов, для каждого типа аккаунтов нужно реализовавать своего наследника. В данной работе каждый Creator делает запрос в нужную бд, на основе полученных данных создает соответствующий Account и возвращает shared_ptr на него. 
#### AccountCreatorsManager
Возвращает нужного Creator'a на основе входных данных и ассоциаций у AccountTypesManager'a. В данной работе - ищет в бд, в какой таблице аккаунт и возвращает нужного Creator'a.
#### AccountTypesManager
Данный класс управляет ассоциациями между типами аккаунтов, именами таблиц и наследниками AccountCreator.

### Добавление нового аккаунта
Для того, чтобы добавить новый аккаунт и начать с ним работать, необходимо добавить тип аккаунта в accounts::type, Создать наследника класса Account и наследника AccountCreator(в котором реализовать механизм построения нового аккаунта). Далле нужно добавить для AccountTypesManager'a информацию об ассоциациях между типом и Creator'ом и типом и именем таблицы, из которой берется информация - то есть, положить новые пары ключ-значение в мапы AccountTypesManager'a.

### Товары
Архитектура товаров схожа с архитектурой аккаунтов: есть Item, ItemCreator, ItemCreatorsManager, ItemTypesManager.

### Стратегии(политики) валидации
Архитектура стратегий валидации похожа на Account и Item, за исключением того, что так как для каждого аккаунта необходимо реализовывать отдельную для каждого товара стратегию валидации, были добавлены другие элементы.

#### PolicyCreator
Создает нужную AccountPolicy на основе аккаунта.

#### AccountPolicy
Абстрактный класс, определяющий, какую стратегию валидации ItemPolicy выбрать для конкретного типа аккаунта. 

#### ItemPolicy
Абстрактный класс для конкретной реализации стратегии валидации.

#### PolicyTypesManager и ItemPolicyTypesManager
Управляют ассоциациями: PolicyTypesManager управляет AccountPolicy на основе типа аккаунта, а ItemPolicyTypesManager - ItemPolicy, на основе типов аккаунта и товара.

#### Добавление стратегии валидации
Для того, чтобы добавить новую стратегию валидации, нужно реализовать AccountPolicy, ItemPolicy для каждого Item'a, и добавить ассоциации в нужные мапы.
