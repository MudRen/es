#include <mudlib.h>

inherit MONSTER;

void create()
{

        ::create();
        set_level(1);
        set_name( "dove", "����" );
        add ("id", ({ "dove" }) );
	set( "unit", "Ⱥ" );
        set_short( "�ܶ�ֻ����" );
        set_long(
           "һֻ��ѱ��С�׸룬�����е��ڹ㳡��������\n"+
           "���ƺ�ע�⵽�����˺��Ƶľ����⣬����ע��������\n"+
           "�ֶ������\�˰�\ͷ�������������ʲ��......��\n"
        );
        set_perm_stat("str", 1);
        set_perm_stat("dex", 5);
        set ("natural_armor_class", 10);
        set ("gender", "male");
        set ("race", "����");
        set("alignment",300);
        set("natural_max_damage1",10);
        set("natural_min_damage1",5);
        set_c_limbs(({"����","ͷ��","���","�Ų�"}));
	set_c_verbs(({ "%s�����������%s��ȥ"}));
}

void init()
{
 add_action("kill_dove","kill");
}

int kill_dove(string arg)
{
 if( arg == "dove" && random(10) > 4 )
 {
  object dove;
  dove=this_object();

   tell_room( environment(this_object()),
        "��Ⱥ�ƺ��ܵ��˾��ţ���Ⱥ��ӵط��𣮣�����\n"+
        "�����ڿ��У�������",
        this_object());
    dove->remove();
   return 1;
 }
 else
 {
  this_player()->command("kill"+arg);
 }
}

void die()
{
   object killer;

   killer = query("last_attacker");
   if( killer ) killer->set_explore("noden#37");
   ::die();
}
