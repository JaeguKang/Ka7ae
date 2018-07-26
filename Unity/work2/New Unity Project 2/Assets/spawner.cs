using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class spawner : MonoBehaviour {
	public GameObject[] wallPrefap;
	
	public float interval = 1.5f;
	public float range = 3;
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

		if(term>=interval)
		{
			Vector3 Pos = transform.position;
			Pos.y += Random.Range(-range, range);
			int wallType = Random.Range(0, wallPrefap.Length);
			Instantiate(wallPrefap[wallType], Pos, transform.rotation);
			
			
			term -= interval;
		}
	}
}
