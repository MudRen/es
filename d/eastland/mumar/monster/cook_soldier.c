#include <../mumar.h>
inherit "/d/eastland/mumar/monster/mob_special";
 
void create()
{
        object ob;
        ::create();
        set_level( 3 );
        set_name( "cooking soldier", "�﷿��" );
        add ("id", ({ "soldier" }) );
        set_short( "�﷿��" );
        set_long( @C_LONG
����һ�����͵Ļ�򣬿����������ϲ����ݹ������Եúܸ��ˡ�
C_LONG
);
        set( "gender", "male" );
        set( "race", "human" );
 
        set("hit_points", 100);
        set( "wealth/silver", 20 );
        set_natural_armor( 16, 6 );
        set_c_verbs(({"%s��ͷײ��%s","%s���������%s","%s�ý�����%s"}));
        wield_weapon(OBJS"scoop");
        set("special_attack",(["damage_type" : "none","main_damage" : 8,
                                "random_dam" : 4 , "hit_rate" : 10]));
        set( "tactic_func", "my_tactic" );
        set("c_enemy_msg",
            "�﷿������������һ�Ѳ������������������..\n\n");
        set("c_room_msg","�ǻ﷿�����ϸ���һ���Ц��ͬʱ����һ��ʣ����������");
        set("c_room_msg2", "����...������Ҷ���һ�ѵ�.....\n");
 
        set( "chat_chance", 5 );
        set( "chat_output", ({
        "�﷿��˵�� : ͷͷ�⼸�������(mood)����ֵֹ�,��֪������...\n",
        "�﷿�������ӽ������������...\n"
        }) );
}
