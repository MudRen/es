#include "../island.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "e shi", "һ��" );
	add ("id", ({ "e", "shi","monk" }) );
	set_short( "һ��" );
	set_long(@LONG
һ�������ְ����ѵ�һ������ţ�����ͨ������ʮ�����������������
ȴ���ᣬ��Լ����ʮ����ѣ���Ȼ���书�ܺã������������Ȥ������
ʷ�о��͹ż������������������о�������ϵĴ�˵�������������
�����֣������Եúܸ��˵����ӣ���������й��о�(research)���¡�
LONG
	);
	set( "alignment",1000);
	set( "gender", "male" );
	set( "race", "lizardman" );
	set( "unit", "λ" );
	set_perm_stat( "dex", 29 );
	set_perm_stat( "str", 27 );
	set_perm_stat( "int", 20 );
	set_perm_stat( "con", 24 );
	set_perm_stat( "piety", 29);
	set_perm_stat( "karma", 30);
	set_skill("unarmed",100);
	set_skill("dodge",100);
        set_skill("parry",80);
	set("special_defense", ([ "all":40, "none":30 ]) );
	set("aim_difficulty", ([ "critical":45, "vascular":40, ]) );
	set("max_hp", 1000);
	set("max_fp", 5000);
	set("hit_points", 1000);
	set("force_effect", 5);
	set("force_points", 5000);
	set("attack_skill",CLASS"dragon_claw");    
	set("defense_skill",CLASS"body_def");
	set("monk_gonfu/dragon-claw",100);
	set("monk_gonfu/body-def",100);
	set("monk_gonfu/power-finger",100);
	set("monk_gonfu/bolo-fist",100);
	set("monk_gonfu/keep-flower",100);
	set("wealth/gold", 10);
	set_natural_weapon( 100, 15, 36 );
	set_natural_armor( 40, 15 );
        set("weight", 500);
        set("chat_chance",20);
	set("att_chat_output", ({"\n", "\nһ��ȵ� �����������צ��!!!��\n\n " 
	}) );
	call_out("mygonfu1",25);
       equip_armor( IOBJ"cloth01.c" );
       equip_armor( IOBJ"boots01.c" );
       set("inquiry",([
            "research": "@@research",
            "war"     : "@@war",
            "peace"   : "@@peace"
               ]) );
}
void mygonfu1()
{ 
  delete("att_chat_output");
  set("att_chat_output",({"\n","\nһ��Ϻ�һ�����������������ָ�ɣ���\n\n"}));
  delete("attack_skill");
  set("attack_skill",CLASS"power_finger");
      call_out("mygonfu2",25);
 } 
 void mygonfu2()
 {
   delete("att_chat_output");
   set("att_chat_output",({"\n","\nһ���ú�ΰ������˵������ʶ��ʶ�����ưɣ���\n"}));
   delete("attack_skill");
   set("attack_skill",CLASS"bolo_fist");
   call_out("mygonfu3",25);
}
void mygonfu3()
{ 
    delete("att_chat_output");
    set("att_chat_output",({"\n","\nһ��΢Ц˵����������ӽ���ָ�𣿡�\n\n"}));
    delete("attack_skill");
    set("attack_skill",CLASS"keep_flower");
    call_out("mygonfu4",25);
    
}
void mygonfu4()
{
    delete("att_chat_output");
    set("att_chat_output",({"\n","\nһ��񺰵�����С�ӣ�����צ������ʰ��ɣ���\n\n"})); 
    delete("attack_skill"); 
    set("attack_skill",CLASS"dragon_claw");  
    call_out("mygonfu1",25);
}  

void research()
{
  write(@LONG
һ����ͷ��������һ��ѡ������ϣ�ͷҲ��̧��˵��
     ����λ��̨������Ҫ��ս��(war)ʷ�أ������ʺ�ƽ(peace)ʷ����
LONG
       );
  return ;
}

void war()
{
  write( set_color(@LONG
  
һ��ͻȻ�������ɶ�� �����ȿ�ˮ���һ����������� ����ࡣ���
 
˵�����������ؿڰ���һ�ƣ�����ú����������ˣ����ȥ��ҽ����

LONG
      ,"HIM") );
      this_player()->set("hit_points",(int)this_player()->query("hit_points")/10 );
      if( (int)this_player()->query("force_points") )
      { 
        this_player()->set("force_points",(int)this_player()->query("force_points")/10 );
      }
         this_player()->set("spell_points",(int)this_player()->query("spell_points")/10 );
       return ;   
}

void peace()
{
  write(@LONG
  һ����������֪�����ӵ�����㣬�ۿ���������ˮ˵��

    ���......���˹��ĺ�ƽ�ˣ������ҵ��о��������ԭ�ǡ�������ʥ��ʿ��
����ʱ�Ǹ�������ǿ��սʿ��ͬʱ�����¸����أ������������������ʹ����
�ܵ�����������𾴣��������������ֲ���ʱ���������˼����µġ�������ꪡ�
�������е�ͣ��������ħ�����ȴ����Ϊ����˽�ģ����͵Ϯʩ��ʯ��ħ������
��Ԫ�����߲����Լ�����������������������ú�ƽ��������϶���ڣ���֮��
Ŀǰ�ĺ�ƽ�Ǽ����ȶ��ģ������Ʋ⣬ֻҪԪ��ص�����ʹʥ��ʿ�������
������(beg)����Ȼս��������ʱ�ᱬ���ģ�  
LONG
      );
  return ;
}
