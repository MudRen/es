#include "mudlib.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name("cook", "��ʦ");
	set_short("æµ�ĳ�ʦ");
	set_long(@CLONG
�����ʦ���������������е���׼��ʳ���û����������������
����һ���ˡ����ۡ��̴ӡ�����Ů��
CLONG
	);
	set_perm_stat( "kar", 30 );
	set_skill( "dodge", 50 );
	set( "natural_armor_class", 40 );
	set( "natural_weapon_class1", 9 );
	set( "natural_min_damage1", 5 );
	set( "natural_max_damage1", 9 );
	set( "alignment", 150 );
	set( "wealth/gold", 5 );
        set( "inquiry", ([
	        "fat": "@@ask_fat",
        ]) );
}
int ask_fat()
{
command("look "+(string)this_player()->query("name"));
if (!(this_player()->query_temp("fat_quest/fish")) || this_player()->query_temp("fat_quest/fish")<3) {
write(
"��ʦ�ɻ�Ŀ����㣬˵��: �Ҳ�����ְ�??\n");
}
else {
write(
"\n��һ��һʮ�İѷʶ������Ѹ����˳�ʦ��һ���Ĭ֮�ᣬ��ʦ˵��: �����ͽ��\n"
"���ǲ�������һ��СС������ͻ���ɥ־����������ʧ����һ����ʦ����Լ���ʧ\n"
"ȥ���ģ��ǿ������������������? ��ʮ����ǰֻ����һ�룬����Ҫ���Լ��ɳ���\n"
"��������������.......\n");
call_out("help_fat",10,this_player());
return 1;
}
}
int help_fat(object ob1)
{
	object ob;
      if ( present("cook note",ob1) ) return 0;
      else {
write(
"��ʦ����˵��: ���ˣ�˭��������ͽ���أ��ٰ���һ��æ���ˡ�˵��ת���\n"
"����������з�����һ��СС�ıʼǱ���˵��: ��������Щ�������������\n"
"�ĵã�Ӧ�ÿ��԰���һ��æ������Ҫ�����������������������ȥ����\n"
"����˿�����죬�����ȥ�����ǲ��Ұ��ĵó��ڱʼ���һ�����ȥ....\n");
ob1->set_temp("fat_quest/skill",1);
   ob = new("/d/eastland/liang_shan/obj/note");
   ob->move(ob1);
return 1;
}
}
