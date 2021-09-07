using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;
using UnityEditor.SceneManagement;
using System.IO;


public class CheatWindow : EditorWindow
{
    string[] cheatList = new string[] { "Cheat", "Gold", "Point", };

    static int selectIndex = 0;
    int getInt = 0;
    string getString = "";

    [MenuItem("InhaMenu/SubMenu/CheatMenu 1", false, 0)]
    static public void OpenCheatwindows1()
    {
        CheatWindow cheatWndow = EditorWindow.GetWindow<CheatWindow>(false, "Cheat Window", true);
    }

    private void Update()
    {
        Repaint();
    }

    private void OnGUI()
    {
        GUILayout.Space(10.0f);
        int getIndex = EditorGUILayout.Popup(selectIndex, cheatList, GUILayout.MaxWidth(200.0f));
        if (selectIndex != getIndex)
        {
            selectIndex = getIndex;
        }

        GUILayout.BeginHorizontal(GUILayout.MaxWidth(300.0f));
        string cheatText = "";

        switch (selectIndex)
        {
            case 0:
                GUILayout.Label("Input Cheat", GUILayout.Width(70.0f));
                getString = EditorGUILayout.TextField(getString, GUILayout.Width(100.0f));
                cheatText = string.Format("Cheat : {0}", getString);
                break;

            case 1:
                GUILayout.Label("Gold", GUILayout.Width(70.0f));
                getString = EditorGUILayout.TextField(getInt.ToString(), GUILayout.Width(100.0f));
                int.TryParse(getString, out getInt);
                cheatText = string.Format("Gold : {0}", getInt);
                break;

            case 2:
                GUILayout.Label("Point", GUILayout.Width(70.0f));
                getString = EditorGUILayout.TextField(getInt.ToString(), GUILayout.Width(100.0f));
                int.TryParse(getString, out getInt);
                cheatText = string.Format("Point : {0}", getInt);
                break;
        }
        GUILayout.EndHorizontal();

        GUILayout.Space(20.0f);
        GUILayout.BeginHorizontal(GUILayout.MaxWidth(800.0f));
        {
            GUILayout.BeginVertical(GUILayout.MaxWidth(300.0f));
            {
                GUILayout.BeginHorizontal(GUILayout.MaxWidth(800.0f));
                {
                    if(GUILayout.Button("\nAply\n", GUILayout.Width(100.0f)))
                    {
                        if(EditorApplication.isPlaying && EditorSceneManager.GetActiveScene().name != "Title")
                        {
                            getInt = 0;
                            getString = "";
                            Debug.Log(cheatText);
                        }
                    }
                }
                GUILayout.EndHorizontal();

                GUILayout.BeginHorizontal(GUILayout.MaxWidth(300.0f));
                {
                    if (GUILayout.Button("\nBackground\nexecute\n", GUILayout.Width(100.0f)))
                    {
                        Application.runInBackground = true;
                    }
                    if (GUILayout.Button("\nBackground\npause\n", GUILayout.Width(100.0f)))
                    {
                        Application.runInBackground = false;
                    }
                }
                GUILayout.EndHorizontal();
                
            }
            GUILayout.EndVertical();
        }
        GUILayout.EndHorizontal();
    }
}
