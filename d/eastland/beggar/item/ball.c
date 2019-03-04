#include "/d/eastland/beggar/dony.h"

inherit ARMOR;

#define EFFECT_ID "potential"
#define FP 60
#define INT 80
#define HP 150

void create()
{
        set_name( "cele ball", "������" );
        add( "id", ({ "ball" }) );
        set_short( "������" );
        set_long(@C_LONG
����һ�Ű�ɫ��ССԲ�򡣾�˵�����������и�����е���������𻯲Ż�����
�����Ķ�����һ�����, �����Ӻ�������һ���ľ�����Ϊ,����ܵõ���������, 
��������ǿ�����ΪҲ˵�����!!���������������( hold )���Ƿ���ʲ���ջ�
C_LONG        
        );
        set( "unit","��" );
        set( "weight", 5 );
        set( "prevent_drop", 1 );
        set( "prevent_get", 1 );
}

void init()
{
   add_action( "hold_ball", "hold" );
}

int hold_ball(string str)
{
   
   int i,mod,skill_no,normal_skill,my_fp,my_int,my_hp;
   mixed skill_name ;
   mapping skills ;
   
   my_fp=(int)this_player()->query("force_points");
   my_int=(int)this_player()->query("spell_points");
   my_hp=(int)this_player()->query("hit_points");
   if( !str || !id(str) )
        return notify_fail( "��Ҫ��ʲ��?\n" );
  
   if ( ( my_int < INT ) && ( my_fp < FP ) )
        return notify_fail( "\n��,���޷����������ӵ�����!!\n\n" );
   
   if ( my_hp < HP )
        return notify_fail( "\n��,���������̫������!!\n\n" );
        
   if( this_player()->query_temp("acup_effect/"+EFFECT_ID) ){
      return notify_fail("\n��,�����Ϊ�Ѿ������˼���!!\n\n");
   }
   else{
       this_player()->set_temp("acup_effect/"+EFFECT_ID,1);
       skills = this_player()->query_skills() ;
       skill_name = keys(skills) ;
       skill_no = sizeof(skill_name) ;
       
       for(i=0;i<skill_no;i++){
           normal_skill=this_player()->query_perm_skill(skill_name[i]) ;
           mod = (normal_skill/20);
           this_player()->modify_skill( skill_name[i] , mod ) ;
           skills[skill_name[i]] = mod ;
       }
       write( "\n��!!һ������������������,��֪���������еļ��ܶ�������!!\n\n" );
       if ( my_fp < FP )
         this_player()->add( "spell_points", -INT );
       else this_player()->add( "force_points", -FP);
       this_player()->set("hit_points",10);
       call_out( "run_out", 300 );
   }
   return 1;
}

void run_out()
{
   object owner;
   int i,skill_no,mod_val ;
   mixed skill_name ;
   mapping skills ;
               
     owner = environment(this_object());

     skills = owner->query_skills() ;
     skill_name = keys(skills) ;
     for(i=0 ; i <sizeof(skill_name);i++){
         mod_val = skills[skill_name[i]] ;
         mod_val=(mod_val/20);
     if(!(mod_val))
       tell_object(owner,"��ļ��ܵ����ƺ�������,����Ǣ��ʦ�����\n") ;
     else
       owner->modify_skill(skill_name[i],  -mod_val );
     }
     tell_object( owner, "\n�������������ʼ��ʧ�� ...\n\n" );
     owner->delete_temp("acup_effect/"+EFFECT_ID);
}
