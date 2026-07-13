#pragma once

#include <cstddef>
#include <optional>
#include <string>

namespace taskhub {

enum class TaskStatus { Todo, Doing, Done };

std::string to_string(TaskStatus status);
std::optional<TaskStatus> task_status_from_string(const std::string& value);

struct Task {
    long long id{};
    std::string title;
    std::string description;
    TaskStatus status{TaskStatus::Todo};
    std::string created_at;
    std::string updated_at;
};

struct CreateTask {
    std::string title;
    std::string description;
};

struct UpdateTask {
    std::optional<std::string> title;
    std::optional<std::string> description;
    std::optional<TaskStatus> status;
};

struct TaskStats {
    std::size_t todo{};
    std::size_t doing{};
    std::size_t done{};
    std::size_t total{};
};

}  // namespace taskhub
