using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BossSpawner : MonoBehaviour
{
	public GameObject BossEnemyPrefab;

	public float interval = 1.5f;
	public float range = 3.5f;
	float term;

	// Use this for initialization
	void Start ()
	{
		term = interval;
	}
	
	// Update is called once per frame
	void Update ()
	{
		term += Time.deltaTime;

		if (term >= interval)
		{
			Vector3 Pos = transform.position;
			Pos.x = Random.Range(-range, range);
			Instantiate(BossEnemyPrefab, Pos, transform.rotation);


			term -= interval;
		}
	}
}
