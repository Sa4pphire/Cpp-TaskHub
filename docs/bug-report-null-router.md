# Bug 修复记录：路由允许空服务依赖

## 现象

`ApiRouter` 构造函数原本接受空的 `shared_ptr<TaskService>`。对象能够创建，但第一次处理需要业务服务的请求时会解引用空指针并终止进程。

## 根因

路由对象的有效条件是服务依赖始终存在，但构造函数没有维护这个不变量，把错误推迟到了运行阶段。

## 测试驱动修复

1. 提交 `test: reproduce null router dependency bug`，规定空依赖必须产生 `ValidationError`。
2. 提交 `fix: reject null router service dependency`，只在构造函数中增加空值检查。
3. 运行全部测试，确认修复没有改变正常路由行为。

这个顺序让回归测试能够证明修复原因，并防止未来删除构造校验。
