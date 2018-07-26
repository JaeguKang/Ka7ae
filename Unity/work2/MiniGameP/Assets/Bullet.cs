using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bullet : MonoBehaviour {
	public float firePower = 10;
	Player player;
	Fire SB;
	

	// Use this for initialization
	void Start ()
	{
		player = GameObject.Find(name: "Player").GetComponent<Player>();
		SB = GameObject.Find(name: "Capsule").GetComponent<Fire>();
	}
	
	// Update is called once per frame
	//불릿 속성
	void Update ()
	{
		transform.Translate(0, firePower * Time.deltaTime, 0);

		if(transform.position.y>15)
		{
			Destroy(gameObject);
		}
	}

	
	private void OnTriggerEnter(Collider col)
	{
		if(col.gameObject.tag == "Enemy")
		{
			Destroy(gameObject);
			player.addScore(10);
			SB.addSBscore(10);
		}
		
		//SceneManager.LoadScene(SceneManager.GetActiveScene().name);
	}
}
