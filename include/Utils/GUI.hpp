#pragma once

#include <imgui_internal.h>

namespace Ham
{
namespace GUI
{

inline static void DrawVector3(const std::string& label, Vector3& values, float resetValue = 0.0f, float columnWidth = 100.0f)
{
    // ImGuiIO& io       = ImGui::GetIO();
    // auto     boldFont = io.Fonts->Fonts[0];

    ImGui::PushID(label.c_str());

    ImGui::Columns(2);
    ImGui::SetColumnWidth(0, columnWidth);
    ImGui::Text(label.c_str());
    ImGui::NextColumn();

    ImGui::PushMultiItemsWidths(3, ImGui::CalcItemWidth());
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2{0, 0});

    float  lineHeight = ImGui::GetTextLineHeight() + ImGui::GetStyle().FramePadding.y * 2.0f;
    ImVec2 buttonSize = {lineHeight + 3.0f, lineHeight};

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{0.8f, 0.1f, 0.15f, 1.0f});
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{0.9f, 0.2f, 0.2f, 1.0f});
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{0.8f, 0.1f, 0.15f, 1.0f});
    // ImGui::PushFont(boldFont);
    if (ImGui::Button("X", buttonSize))
        values.x() = resetValue;
    // ImGui::PopFont();
    ImGui::PopStyleColor(3);

    ImGui::SameLine();
    ImGui::DragFloat("##X", &values.x(), 0.1f, 0.0f, 0.0f, "%.2f");
    ImGui::PopItemWidth();
    ImGui::SameLine();

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{0.2f, 0.7f, 0.2f, 1.0f});
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{0.3f, 0.8f, 0.3f, 1.0f});
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{0.2f, 0.7f, 0.2f, 1.0f});
    // ImGui::PushFont(boldFont);
    if (ImGui::Button("Y", buttonSize))
        values.y() = resetValue;
    // ImGui::PopFont();
    ImGui::PopStyleColor(3);

    ImGui::SameLine();
    ImGui::DragFloat("##Y", &values.y(), 0.1f, 0.0f, 0.0f, "%.2f");
    ImGui::PopItemWidth();
    ImGui::SameLine();

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{0.1f, 0.25f, 0.8f, 1.0f});
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{0.2f, 0.35f, 0.9f, 1.0f});
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{0.1f, 0.25f, 0.8f, 1.0f});
    // ImGui::PushFont(boldFont);
    if (ImGui::Button("Z", buttonSize))
        values.z() = resetValue;
    // ImGui::PopFont();
    ImGui::PopStyleColor(3);

    ImGui::SameLine();
    ImGui::DragFloat("##Z", &values.z(), 0.1f, 0.0f, 0.0f, "%.2f");
    ImGui::PopItemWidth();

    ImGui::PopStyleVar();

    ImGui::Columns(1);

    ImGui::PopID();
}

inline static void DrawTransform(Component::Transform& transform)
{
    DrawVector3("Translation", transform.position);
    DrawVector3("Rotation", (Vector3&)transform.rotation);
    DrawVector3("Scale", transform.scale, 1.0f);
}

inline static void DrawTransform(Entity entity)
{
    if (!entity) return;
    if (!entity.HasComponent<Component::Transform>()) return;

    auto& transform = entity.GetComponent<Component::Transform>();
    DrawTransform(transform);
}

inline static void DrawSceneHierarchy(Scene* scene) {

}

} // namespace GUI

} // namespace Ham
