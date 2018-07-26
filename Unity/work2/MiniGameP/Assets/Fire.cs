using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Fire : MonoBehaviour {
	public GameObject bulletPrefab;
	public GameObject SuperbulletPrefab;

	public TextMesh SuperbulletCnt;
	int cntBullet = 0;
	int sbcore = 0;

	// Use this for initialization
	void Start ()
	{
		//SuperbulletPrefab = null;
	}
	
	// Update is called once per frame
	//발사
	void Update ()
	{
		if(Input.GetButtonDown("Jump"))
		{
			Vector3 Pos = transform.position;
			Pos.y += 0.7f;
			Instantiate(bulletPrefab, Pos, transform.rotation);
		}

		if (Input.GetButtonDown("Fire1") && cntBullet > 0) 
		{
			Vector3 Pos = transform.position;
			Pos.y += 0.7f;
			Instantiate(SuperbulletPrefab, Pos, transform.rotation);
			cntBullet--;
			SuperbulletCnt.text = "SuperBullet : " + cntBullet;
		}
	}

	public void addSBscore(int i)
	{
		sbcore += i;

		if(sbcore==100)
		{
			cntBullet++;
			SuperbulletCnt.text = "SuperBullet : " + cntBullet;
			sbcore = 0;
		}
	}
}
