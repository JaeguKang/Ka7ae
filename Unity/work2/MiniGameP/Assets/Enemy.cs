using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Enemy : MonoBehaviour {
	public float speed = 1;

	

	// Use this for initialization
	void Start ()
	{
			
	}
	
	// Update is called once per frame
	//Enemy Apply
	void Update ()
	{
		transform.Translate(0, speed * Time.deltaTime, 0);

		if(transform.position.y<0)
		{
			Destroy(gameObject);
		}
	}
	//충돌처리
	private void OnTriggerEnter(Collider col)
	{
		if(col.gameObject.tag == "Bullet")
		{
			Destroy(gameObject);
		}
	}

}
