using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BossEnemy : MonoBehaviour
{
	public float speed = 1;

	// Use this for initialization
	void Start ()
	{
		
	}
	
	// Update is called once per frame
	void Update ()
	{
		transform.Translate(0, speed * Time.deltaTime, 0);

		if (transform.position.y < 1)
		{
			Destroy(gameObject);
		}
	}

	private void OnTriggerEnter(Collider col)
	{
		if (col.gameObject.tag == "Bullet")
		{
			Destroy(gameObject);
		}
	}
}
