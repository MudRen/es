#include "../dony.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(17);
	set_name( "the elder of couples", "����" );
	add("id",({"couple","couples","elder"}) );
        set_short( "��ɽ���� ����" );
	set_long(@C_LONG
��ɽ�����ڽ����ϼ���������λ, ʮ����ǰһ�ۻ�ɱΪ����ʱ�ġ��㶫������,
��������������ʿ�������������ɽ�����н�������, ����������������,˫ָ
���������,һ����֪������ĳ�ּ���������צ�������Ӧؤ��֮���μ�һ��һ��
�ļ�����,���,�����ɫ���� !!
C_LONG
	);
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment",100 );
	set( "time_to_heal", 7 );
	set_natural_armor( 40 , 40 );
	set_natural_weapon( 50 , 25 , 40);
	set("max_hp",600);
	set("hit_points",600);
	set("force_points",500);
	set_perm_stat( "str", 25 );
	set_perm_stat( "dex",25 );
	set_skill( "parry",50 );
	set( "wealth/silver",200);
	set( "special_defense", ([ "all": 22 ]) );
	set( "aim_difficulty",(["critical":70,"vascular":30,"weakest":50]) );
	set("couple",1);
        set_c_verbs( ({ "%sʹ���� �� �� צ ����һʽ, ���ִ���%s",
                        "%s�������ʹ���� �� �� צ ���ڶ�ʽ, ˫�������Ѽ�ץ��%s",
                        "%s���һ��, �� �� �� צ ������ʽ��%s���˹���",
                        "%s��צΪ��ʹ���� �� �� צ ����ǿһʽ,������Ӱ��%s���˹���"
                      }) ); 
        equip_armor(DARMOR"couple_cloak");
        set( "tactic_func", "my_attack" );
        set("inquiry", ([
                 "pill":"@@ask_pill"
        ]) );
        set( "chat_chance", 30 );
        set( "att_chat_output", ({
              "��ɽ���� ���Ͽ�Ц��:���ú�������,���ǲ�������!! \n"
           }) );
} 

void ask_pill(object asker)
{

   if ( this_object()->query("have_asked") )
      tell_object( asker,
         "��ɽ���� ����˵��:��,��λ�ú���������,�ҲŰ������������...\n");
   else {
     this_object()->set("have_asked",1);
     tell_object(asker,
         "��ɽ���� ����˵��:Ŷ,���ʾ�ת�������?\n"
         "����������������������⡣\n"
         "��ɽ���� ����˵��:���һ�¡�\n\n"
         "��˼����һ�����\n\n"
               );
     call_out("recover1",3,asker);             
     call_out("recover2",1800,this_object());
   } 
}
void recover1(object obj)
{ 
   object ob1;
   ob1=new(DITEM"pill");
   ob1->set("master",obj->query("name"));
   tell_object(obj,
      "��ɽ���� ����˵��:��Ȼ��Ҫ��������,���Ҿ͸���һ�Űɡ�\n"
         );
   ob1->move( this_object() );
   command("give pill to "+obj->query("name"));
   tell_object(obj,
      "��ɽ���� ����˵��:�벻Ҫ�˷��������,�����Һܲ����ײ����ɵġ�\n"
      "������ɽ���� ���ϵ��˵�ͷ��\n"
               );
}
void recover2(object obj)
{
    obj->delete("have_asked");
}

int can_help( object ob )
{
    if( ob->query_attacker() ) return 0;
    if( ob->query("couple") ) return 1;
       return 0;
}

int my_attack()
{ 
   object *couples,victim;
   int i;

   victim = query_attacker();
   if( !victim ) return 0;
    
   couples = filter_array( all_inventory(environment(this_object())),
           "can_help", this_object() );
   for( i=0; i<sizeof(couples); i++ ) {
      tell_room( environment(this_object()), couples[i]->query("c_name")+
          "ŭ��:��������������۸���,�����µ���ȥ��!!\n",
          couples[i]);
      couples[i]->kill_ob(victim);
   }

   if  (random(5)>1)  return 0;
   else{
       tell_room( environment(this_object()),set_color(
           "\n��!ͻȻ��������Ʊ�ɺ�ɫ�����͵�����,����"+
           victim->query("c_name")+"����ǰ......\n","HIG",victim),victim);
       tell_object( victim,set_color(
           "\n��!ͻȻ��������Ʊ�ɺ�ɫ�����͵�����,���������ǰ......\n","HIG",victim));
       (CONDITION_PREFIX + "simple_poison")->apply_effect( victim, 5 , 3 );
       return 1;
   }      
}


void die()
{
    object ob1,last_hit;
    
       last_hit=this_object()->query("last_attacker");
       if ( ( !(last_hit->query_temp("have_ball"))) &&
            ( last_hit->query("class")!="healer" ) 
       ){
           last_hit->set_temp("have_ball",1);
           ob1 = new( DITEM"ball" );
           ob1->move(last_hit);
           tell_object(last_hit,"\n��!!�������ֿ�ش�"
               +this_object()->query("c_name")+"������ȡ��������\n\n");
        }::die(1);
 }