
#include "../goomay.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(12);
        set_name( "Jor the roger", "������" );
        add ("id",({ "jor","roger"}));
        set_short( "������");
        set("unit","��");
        set_long(
@C_LONG
����������ֵ����Ƿ���Ĵ�������ģ�һ��ʮ�ֿ���ĺ��ӣ�ȴ����
�����������������ڶ�Ѩ����һ�ˣ����޼ɵ��Ĵ������㡣
C_LONG
);
        set("alignment",-550);
        set("wealth/gold",30);
        set_perm_stat("str",20);
        set_perm_stat("dex",25);
        set_perm_stat("int",17);
        set_natural_armor( 72, 11 );
        set_natural_weapon( 20, 13, 20 ); 
        set_skill("dodge",65);
        set_skill("unarmed",100);
        set ("gender", "male");
        set ("race", "human");
        set( "special_defense", ([ "all": 20 ]) );

        set( "inquiry", ([
                "statue": "@@ask_statue",
        ]) );

}
int ask_statue()
{
        tell_object(this_player(),
	"������аЦ������֪������������������ !! �κ��¶��㶼����Ҫ�� !!��\n" 
		    );

		command("kill "+(string)this_player()->query("name"));
		return 1;
}
void die()
{
	object killer;
	killer = this_object()->query("last_attacker");
	tell_room( environment(), 
	"�����Ĳҽ�һ����ˤ���ڵأ���Ҳ���������ˣ�����ݺݵص����㣬����ȴ������ս ...\n\n" ,
	this_object() );
        tell_object(killer,
@C_STATUE
������ͻȻ������Ц����������� ...������ ...�㻹Ҫ������˵�Ļ��������
�Դ�͵����һ���������������Ӿ͵�����ˣ������ǹ��������ϲŻ������ӽ�����
�����ã�ƫƫ���������������ܣ�ÿ�챻һЩ����ֵֹ���ħ���׷��׷ȥ��������
����ֻ�������ˣ�һֻȫ��ð�����棬һֻ��ͷ����������Ϊ�һ����ˣ���ʼ��
�������������ң��Ҽǵ��Ǹ��������������������Ǹ������ˣ����������ʱ����
����̫ү���������������Ϊʲ��ƴ��������Ҫ�ӵ�ԭ��С͵�������˼����η�
�������������ֵ�����... ���㲻��ҲҪ��������ˡ��������������ͱ�������
ȥ�ˣ��һ���������ʲ�᣿����������һ��������ֻ����Ҫ�������������˵�ע����
���ˡ��Ų������㣬�����������ֿտգ���֪���ᱻ������������ˡ���

����Ц��Խ��Խ�ͣ�����ͷһ�ᣬ���ڵ��ϣ����� !!
C_STATUE
                        );
        killer->set_temp("meet_jor",1);
	::die(1);

	return;
}
