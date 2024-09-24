#include "overlay.h"
#include "draw_utils.h"
#include "globals.h"
#include <imgui.h>
#include <d3dx11.h>
#include <d3d11.h>

void overlay::draw_gui()
{
    ImGui::SetNextWindowSize(ImVec2(400, 500));
    ImGui::SetNextWindowPos(ImVec2(15, 40));

    ImGui::Begin("gui", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove);
    {
        // Top bar
        ImGui::BeginChild("TitleBar", ImVec2(0, 30), false, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar);
        ImVec2 windowSize = ImGui::GetWindowSize();
        ImVec2 textSize = ImGui::CalcTextSize("Yester");
        ImGui::SetCursorPosX((windowSize.x - textSize.x) / 2);
        ImGui::SetCursorPosY((30 - textSize.y) / 2);
        ImGui::Text("Yester Menu");
        ImGui::Text("By ArrestWarant");
        ImGui::EndChild();

        // Main
        ImGui::BeginChild("MainContent", ImVec2(0, 0), true);

        // Player Category
        if (ImGui::CollapsingHeader("Player"))
        {
            static bool walkspeedCheckbox = false;
            static bool jumppowerCheckbox = false;
            static float walkspeedSlider = 16.0f;
            static float jumppowerSlider = 50.0f;

            ImGui::Checkbox("Walkspeed", &walkspeedCheckbox);
            ImGui::Checkbox("Jumppower", &jumppowerCheckbox);

            ImGui::SliderFloat("Walkspeed", &walkspeedSlider, 16.0f, 1000.0f);
            ImGui::SliderFloat("Jumppower", &jumppowerSlider, 50.0f, 1000.0f);
        }

        // ESP Category
        if (ImGui::CollapsingHeader("ESP"))
        {
            ImGui::Checkbox("Box", &boxCheckbox);
            static bool nameCheckbox = false;
            static bool healthCheckbox = false;
            static bool distanceCheckbox = false;

            ImGui::Checkbox("Name", &nameCheckbox);
            ImGui::Checkbox("Health", &healthCheckbox);
            ImGui::Checkbox("Distance", &distanceCheckbox);
        }

        // Aimbot Category
        if (ImGui::CollapsingHeader("Aimbot"))
        {
            static bool aimbotCheckbox = false;
            ImGui::Checkbox("Aimbot", &aimbotCheckbox);
        }

        // Settings Category    
        if (ImGui::CollapsingHeader("Settings"))
        {
            static bool crosshairCheckbox = false;
            static bool fovCheckbox = false;
            static bool smoothCheckbox = false;
            static float smoothSlider = 1.0f;
            static float fovSlider = 90.0f;

            ImGui::Checkbox("Crosshair", &crosshairCheckbox);
            ImGui::Checkbox("FOV", &fovCheckbox);
            ImGui::Checkbox("Smooth", &smoothCheckbox);

            ImGui::SliderFloat("Smooth", &smoothSlider, 1.0f, 10.0f);
            ImGui::SliderFloat("FOV", &fovSlider, 30.0f, 120.0f);
        }

        ImGui::EndChild();
    }
    ImGui::End();
}
