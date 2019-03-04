/*
Quest:
	����һ: ����ϵĺ�����¥... ��ʧ��СŮ��
	������: ���ݡ�����ʫ��֮��
	������: ��������ñ
	������: ��˯����Ů
	������: è֮����
	������: 
*/

#include "../ekravia.h"
inherit "/d/erosmia/ekravia/quest_d";

object	girl;
object	hat;

void	init_quest()
{
	add_scene( "vanished_girl", "girl_disappear");
	add_scene( "abandon_house", "in_the_house");
	switch_scene( "vanished_girl" );
}

void	girl_disappear(string signal)
{
	if (query_flag( "girl_looked" )) return;

	if (signal == "look_girl")
	{
		set_flag( "girl_looked", 1);
		if (girl) girl->remove();
		switch_scene( "abandon_house" );
	}
}

void	in_the_house(string signal)
{
}
