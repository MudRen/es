#include <mudlib.h>

inherit MONSTER;
void create()
{
    ::create();
    set("palace_war",1); 
}        
void hurt_all(string type,int damage)
{
    int i,max;
    object *atk;
    atk=all_inventory(environment(this_object()));
    max=sizeof(atk);
    for ( i=0;i<max;i++ )
       if ( living(atk[i]) && ( !atk[i]->query("palace_war") ) )
          atk[i]->receive_special_damage(type,damage);
}
void kill_reward(object killer)
{
    int points;
    string class1,type;
    points=(int)query("war_points");
    class1=killer->query("class");
    switch ( class1 ) {
    case "knight": 
          killer->add("war_score",points);
          tell_object(killer,sprintf("��õ�  %d  ��սѫ��\n",points));  
          break;
    case "mage" :    
        
           switch( random(2) ) {
           case 0 : 
             points=points/2;
             type="spell_exps/black-magic";
             break;
           case 1 :
             points=points*7/10;
             type="spell_exps/elemental";
             break;
           default :
             type="spell_exps/misc";    
             break;
           }  
        
       killer->add(type,points);
       tell_object(killer,sprintf("��������Կ���ȴ������ö���  %d  ��ħ�����顣\n",points));
       break ;        
    default :
        break;
    }
    ::kill_reward(killer);
}

