#include <mudlib.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "Ro Yubin", "�����" );
	add( "id", ({ "ro", "yubin", "scholar" }) );
	set_short( "������ �����" );
	set_long("@@query_long");
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", 1000 );
	set( "hit_points", 1000 );
	set( "max_hp", 1000 );
	set( "max_fp", 3000 );
	set( "force_points", 3000 );
	set_natural_armor( 120, 50 );
	set_natural_weapon( 28, 10, 15 );
	set_perm_stat( "str", 25 );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "int", 30 );
	set_perm_stat( "pie", 20 );
	set_perm_stat( "con", 20 );
	set_perm_stat( "kar", 30 );
	set_skill( "longblade", 100 );
	set_skill( "parry", 100 );
	set_skill( "dodge", 100 );
	set_skill( "inner-force", 100 );
	set_skill( "tactic", 100 );
	set( "tactic", "melee" );
        set( "tactic_func", "my_tactic");
        set( "flute",0);
	set( "force_effect", 8 );
	set( "force_type", "cold" );
	set( "wealth/gold", 300 );
	set( "attack_skill", "scholar/poem" );
	set( "scholar_gonfu/poem", 50 );
        set( "class", "scholar");
	set( "special_defense", ([ "all": 50,"none":60 ]) );
	set( "aim_difficulty", ([ "vascular":80 ]) );
   
//	wield_weapon( "/d/scholar/scholar/weapons/ebonysword" );
}

string query_long()
{
  if (!(this_object()->query("flute")))
    return  "�㿴��һλ��ò���ŵ���������������һ�ź�̴ľ�����Աߣ����ϰ�\��һֻ��������\n"+
  "����һ�����Ʋ����ľ��飬���۾�����ض�����\n";
  else
    return "�㿴��һλ��ò���ŵ���������������һ�ź�̴ľ�����Աߣ�һֻ������һֻ��������\n"+
  "��һֻ��������һ�����Ʋ����ľ��飬���۾�����ض�����\n";
}

int my_tactic(string arg)
{
  object ob;
  int rrr;

  ob=this_object()->query_attacker();
  if (this_object()->query("flute")) {
    rrr=random(15);
    if (rrr<4) {
      tell_room(environment(this_object()), set_color(
         "\n�����ͻȻ�ѹ������õ���ߴ���һ�����������.....\n\n"
      ,"HIR",ob));
    }
    if (rrr<5) {
      switch (rrr) {
       case 0:
         tell_object(ob,set_color( "���������ͻȻ�ѿ�����ؾ�����г��˳�������ʩչ���ı�ɱ����ʮ�������ۡ�\n","HIM",ob));
         tell_room(environment(this_object()),set_color("���������ͻȻ�ѿ�����ؾ�����г��˳�����"+ob->query("c_name")+"ʩչ���ı�ɱ����ʮ�������ۡ�\n","HIM",ob),ob);
         ob->block_attack(2);
         ob->set_temp("msg_stop_attack", "�� �����ڱ���ؾ����ס���������ã��޷����� ��\n");
         command("scholar �ɶ��"+(string)ob->query("c_name")+"�����ܵ�������������Ұ !!\n");
         break;      
       case 1:
         tell_object(ob,set_color("ͻȻ����һ������������Ю������֮�ƴ������������ѿ�һ�ţ��������������һ�Ż����\n","HIR",ob));
         tell_room(environment(this_object()),set_color("ͻȻ����һ������������Ю������֮�ƴ������������ѿ�һ�ţ���������"+ob->query("c_name")+"���һ�Ż����\n","HIR",ob),ob);
         ob->receive_special_damage("fire",20);
         command("scholar ������ ! ���Ұ�"+(string)ob->query("c_name")+"�����ˣ����ǾͿ�������װ���� !!\n");
         break;
       case 2:
         tell_object(ob,set_color( "��о���һ������ֱ����������껯��һ�ѱ����ڿ��з�������ͻȻ������һ������Ԫ�����ѱ������������³���������ɫ��â��\n","HIW",ob));
         tell_room(environment(this_object()),set_color( "��о���һ������ֱ����������껯��һ�ѱ�����
���з�������ͻȻ������һ������Ԫ�����ѱ���������"+ob->query("c_name")+"�³���������ɫ��â��\n","HIW",ob),ob);
         BLEEDING->apply_effect(ob,4,5);
         if ((string)ob->query("class")=="scholar")
           command("scholar �벻�� ... "+(string)ob->query("c_name")+"�������ǹ��������ͽ�����ҾͲ������� !!\n");
         else
           command("scholar �ٺ� ! ��Ҫ����"+(string)ob->query("c_name")+"��������һ����ɫ���ƣ����ǲ���Թ������� !!\n");
         break;
       case 3:
         tell_room(environment(this_object()),set_color("��������һ������Ʈ����ˮ�������Ʈ�˳�����ˮ�������ִ�����������˿�֮�ᣬˮ��������������Ʈ���ˡ�\n","HIB",ob));
         this_object()->receive_healing(20);
         command("scholar ������ ! ������У�"+(string)ob->query("c_name")+"�� !!\n");
         break;
      default: 
         command("scholar "+(string)ob->query("c_name")+" !! ����Ľ��������ļ��� !!\n");
         break;
      };
    }
    return 0;
  }
  tell_room(environment(this_object()),"������ ������ӳ��������������\n");
  ob=new("/d/scholar/scholar/weapons/flute");
  ob->move(this_object());
  command("wield flute");
  ob=new("/d/scholar/jade_mark");
  ob->move(this_object());
  this_object()->set("flute",1);
  return 1; 

}

void die()
{
	object killer,weapon,ob;

	killer = query("last_attacker");
	if ( !killer) {
		::die();
		return ; 
	}
        command("scholar "+(string)killer->query("c_name")+" !! ��Ȼ�Ҳ�С�ı����ܣ����ҵ�ԩ�����Զ�Ĳ������ !!!\n");
        ob=query("guild");
        ob->remove();
        weapon=query("weapon1");
        weapon->set("killer",killer);
	::die();
	return;
}
