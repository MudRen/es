#include "../goomay.h"

inherit Mob_special;

void create()
{
	object ob;
	::create();
	set_level( 3 );
	set_name( "woman", "��ͥ����" );
	set_short( "��ͥ����" );
        set_long(
@C_LONG
����һ�����͵��������ţ�������������������֣���������
���˵�һ����������һ�浽�����ˮ���Եú��˷ܡ�
C_LONG
);
	set( "gender", "female" );
	set( "race", "human" );

	set("hit_points", 100);
	set( "wealth/silver", 20 );
	set_natural_weapon( 4, 3, 7 );
	set_natural_armor( 16, 6 );
        set_c_verbs(({"%s��ָ��ץ��%s","%s�ò�������%s","%s�ý�����%s"}));
        ob = new( Obj"basket" );
        ob->move( this_object() );
        set("special_attack",(["damage_type" : "none","main_damage" : 8,
				"random_dam" : 4 , "hit_rate" : 10]));
        set( "tactic_func", "my_tactic" );
set("c_enemy_msg",
    "�Ǹ��������Ĳ��������ͷ��һ������..\n\n");
set("c_room_msg","�Ǹ���������Ƶ��ò�������");
set("c_room_msg2", "��������ð����� ...\n");
        set( "chat_chance", 10 );
        set( "chat_output", ({
                "��ͥ�������ε�˵�������˰������ˣ��⼸�춼û�з������޿��Խ��� ����\n",
	})
	);

}

