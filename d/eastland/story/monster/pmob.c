#include "../story.h"

inherit MONSTER;
void create()
{
    ::create();
    set("pname","����");
    set( "tactic_func", "my_tactic" );
}
int stop_attack()
{
    object other;
    if ( other=query("other") )
      other->kill_ob(this_player());
    return 0;  
}
int catch_huntee( object who )
{
    if ( !query("tail") )
        tell_object(environment(),sprintf("%s�е�: �ɶ������㣡\n"
        ,query("pname")));
    return 1;
}
void check_hp()
{
    int hp1,hp2;
    object other;
    other=query("other");
    if ( !other ) {
       set("hit_points",0); 
       return ;
    }
    hp1=query("hit_points");
    hp2=other->query("hit_points");
    if ( hp2 > hp1 )
      other->set("hit_points",hp1);
    else set("hit_points",hp2);
    return ;   
}
int my_tactic()
{
    object victim,other,env1,env2;
    if ( !victim=query_attacker() ) return 0;
    check_hp();
    if ( query("tail") ) {
      if ( (other=query("other")) && (!other->query_attacker()) ) {
         env1=environment();
         env2=environment(other);        
         tell_room(env1,sprintf("\n%s�ܵ����˵Ĺ�����һ�Խ����ϵ�ͷ������ \n\n",
              query("short")));
         move(env2);
         other->move(env1);        
      }  
      return 1;
    }
    return 0;
}
void die()
{
    object other;
    if ( other=query("other") ) 
       other->set("hit_points",0);
    find_object_or_load(SAREA"room_h")->rr();
    tell_room(environment(),sprintf("%s�ȳ�������Ѫ�����ڵ� ... �ۿ�����ˡ�\n"
       ,query("pname")));
    ::die(1);
}