using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Player : MonoBehaviour {
	float speed = 5;
	public TextMesh scoreOutput;

	int score = 0;

	Fire SB;

	// Use this for initialization
	void Start ()
	{
		SB = GameObject.Find(name: "Capsule").GetComponent<Fire>();
	}
	
	// Update is called once per frame
	//플레이어 조작
	void Update ()
	{
		float keyHorizontal = Input.GetAxis("Horizontal");
		transform.Translate(Vector3.right * speed * Time.deltaTime * keyHorizontal, Space.World);		
	}
	//충돌처리
	private void OnTriggerEnter(Collider col)
	{
		if(col.gameObject.tag == "Enemy")
		{
			SceneManager.LoadScene(SceneManager.GetActiveScene().name);
		}
		
	}
	//스코어
	public void addScore(int s)
	{
		score += s;
		scoreOutput.text = "Score : " + score;
	}
}
