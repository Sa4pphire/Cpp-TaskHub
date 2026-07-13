# 模拟需求单：任务状态统计

## 用户价值

调用者需要快速了解待办、进行中和已完成任务的数量，不希望自己拉取列表后再统计。

## 验收条件

- 新增 `GET /stats`，成功时返回 `200`。
- 响应固定使用 `{"data":{"todo":N,"doing":N,"done":N,"total":N}}`。
- 空数据库的四个值全部为 `0`。
- 混合状态时，各状态计数正确，`total` 等于三项之和。
- 不修改数据库结构，不改变现有 CRUD API。
- 数据库异常仍由现有错误边界映射为 `500`。

## 实现决策

`TaskStats` 是领域结果，`TaskService::stats` 负责统计，`ApiRouter` 只负责 JSON 序列化。当前学习版本复用仓储的 `list` 接口，不新增 SQL。数据规模变大时，可以给仓储增加聚合查询，用 `GROUP BY status` 减少内存和数据传输。

## 测试映射

- `stats are zero when empty`：服务层空数据。
- `stats count mixed statuses`：服务层混合状态。
- `stats endpoint returns counts`：HTTP 状态码和 JSON 契约。
