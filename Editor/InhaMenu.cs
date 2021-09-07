using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;
using UnityEditor.SceneManagement;

public class InhaMenu : MonoBehaviour
{
    [MenuItem("InhaMenu/Clear PlayerPrefs")]
    private static void Clear_PlayerPrefsAll()
    {
        PlayerPrefs.DeleteAll();
        Debug.Log("all prefs removed. ");
    }

    [MenuItem("InhaMenu/Sub/sub1")]
    private static void Sub_sub1()
    {
        Debug.Log("sub1 actived.");
    }

    [MenuItem("Assets/Load Seleceted Scene")]
    private static void LoadSelectedScene()
    {
        var selected = Selection.activeObject;
        if (EditorApplication.isPlaying)
            EditorSceneManager.LoadScene(AssetDatabase.GetAssetPath(selected));
        else
            EditorSceneManager.OpenScene(AssetDatabase.GetAssetPath(selected));
    }


}
