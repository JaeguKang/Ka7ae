using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class player : MonoBehaviour {
	public float jumpPower = 5;
	public TextMesh scoreOutput;
	int score = 0;

	// Use this for initialization
	void Start ()
	{
		
	}
	
	// Update is called once per frame
	void Update ()
	{
		if(Input.GetButtonDown("Jump"))
		{
			GetComponent<Rigidbody>().velocity = new Vector3(0, jumpPower, 0);
		}
	}

	private void OnCollisionEnter(Collision collision)
	{
		SceneManager.LoadScene(SceneManager.GetActiveScene().name);
	}

	public void addScore(int s)
	{
		score += s;
		scoreOutput.text = "Score : " + score;
	}
}
