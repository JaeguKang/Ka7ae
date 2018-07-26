using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SuperBullet : MonoBehaviour
{
	public float firePower = 20;
	
	Player player;

	// Use this for initialization
	void Start()
	{
		player = GameObject.Find(name: "Player").GetComponent<Player>();
	}

	// Update is called once per frame
	//불릿속성
	void Update()
	{
		transform.Translate(0, firePower * Time.deltaTime, 0);

		if (transform.position.y > 15)
		{
			Destroy(gameObject);
		}
	}

	
	private void OnTriggerEnter(Collider col)
	{
		if (col.gameObject.tag == "Enemy")
		{
			player.addScore(10);
		}	
	}
}
