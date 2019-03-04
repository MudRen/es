#include <../goomay.h>
inherit Mob_special;

void create ()
{
        ::create();
        set_level(12);
        set_name( "Lui Chu", "����" );
        add ("id",({ "chu","lui"}));
        set_short( "����");
        set("unit","λ");
        set_long(
@C_LONG
    ������ǰ����һ��ʮ�ֺ���������Ů�ӣ����ʸ��ŵ�����΢Ц�ؿ����㣬
�������飬һ������ƶ��ȴ�ϻ۹��˵Ĺ����������վ�ڻ���֮����������
�����ǣ�������ؿ���������֪��������Ϊ���Եø��������ǻ���Ϊ�˿��ĸ�
���ޡ�
C_LONG
);
        set("alignment",550);
        set_perm_stat("str",17);
        set_perm_stat("dex",17);
        set_perm_stat("int",17);
        set_natural_armor( 72, 21 );
        set_natural_weapon( 6, 4, 9 ); 
        set_skill("dodge",85);
        set_skill("whip",80);
        set ("gender", "female");
        set ("race", "human");
        set( "special_defense", ([ "all": 30 ]) );

        wield_weapon( Obj"ribbon" );
		equip_armor(Obj"web");
        set( "wealth/gold", 30 );

        set( "inquiry", ([
                "root": "@@ask_root",
        ]) );
        set("special_attack",(["damage_type" : "mental","main_damage" : 20,
                                "random_dam" : 10 , "hit_rate" : 15 ]));
        set( "tactic_func", "my_tactic" );
set("c_enemy_msg",
    "�����˿�������������Ĳ��ӣ����㹿��������͸������..\n\n");
set("c_room_msg","��������ػӶ���˿������");
set("c_room_msg2", "������Ҳ͸������ ...\n");

}
int ask_root()
{
	object ob1;
	if (this_player()->query_temp("amaze_root"))
	{
        tell_object(this_player(),
			"����˵�����Ҳ����Ѿ���ҩ�������𣿡�\n");
	return 1;
	}
        tell_object(this_player(),
"����̾��һ������������үҲ���ǵģ�����������������������أ��һ�\n"
"ȰȰ���ģ�лл������ѡ�����ҩ��ܿ�ͻᵽ�� !! �����ó�һ������\n"
"�������������컨���ĸ�����������ȥ���ð� !!��\n" );

        ob1 = new( Obj"amaze_root" );
        ob1->move(this_object());
		this_player()->set_temp("amaze_root",1);
        command("give "+(string)ob1->query("name")+" to "+lower_case((string)this_player()->query("name")));
        return 1;
}
