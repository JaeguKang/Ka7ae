using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class wall : MonoBehaviour
{
	public float speed = -5;
	player _player;

	// Use this for initialization
	void Start ()
	{
		_player = GameObject.Find(name: "player").GetComponent<player>();
	}
	
	// Update is called once per frame
	void Update ()
	{
		transform.Translate(speed * Time.deltaTime, 0, 0);
		

		if (transform.position.x < -10) 
		{
			_player.addScore(10);
			Destroy(gameObject);
		}
	}
}
