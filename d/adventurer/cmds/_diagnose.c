//#pragma save_binary
#include <mudlib.h>
#include "/d/healer/healer.h"
 
inherit DAEMON;
 
int cmd_diagnose(string arg)
{
        object dest;
        int skill,hp,max_hp,i,limit,diff, referance;
        mapping conds,acups;
        string *cond_name,cond_str,*acup_name,acup_str,destname,msg,der;
 
 
        if( this_player()->query_level() < 5 )
                return notify_fail("你到底想干嘛啦?\n");
        if ( !arg || arg == "" ||
             !(dest = present(arg,environment(this_player()))) ) 
                return notify_fail("你要帮谁诊断 ?\n");
 
        if ( ! living(dest) )
                return notify_fail("这个东西没有生命。\n");
        if ( (skill = this_player()->query_skill("diagnose")) == 0 ) 
                return notify_fail ("你并没有学过诊断的技能。\n");
        conds = (mapping)dest->query("conditions");
        acups = (mapping)dest->query_temp("acup_effect");
        cond_str = "";
        if ( sizeof(conds) ) {
                cond_name = keys(conds);
                for( i=0, limit=sizeof(cond_name); i<limit; i++ ) {
                        if( cond_name[i][0] == '_' ) continue;
                        cond_str = sprintf("%s %s", cond_str, 
                                to_chinese(cond_name[i]));
                }
 
        }
        if ( cond_str == "" ) cond_str = "正常";
        acup_str = "";
        if ( sizeof(acups) ) {
                acup_name = keys(acups);
                for( i=0, limit=sizeof(acup_name); i<limit; i++ ) {
                        if( acup_name[i][0] == '_' ) continue;
                        acup_str = sprintf("%s %s", acup_str,
                             USE_POINTS->query_effect_c_name(acup_name[i]));
                }
 
        }
        if ( acup_str == "" ) acup_str = "没有半个";
 
        hp = dest->query("hit_points");
        max_hp = dest->query("max_hp");
        if(!max_hp) return notify_fail("这个生物有问题,请连络巫师。\n") ;
 
//   技能超过 80 就不以 5 为阶层表示          
        if( skill < 80 )       
          { 
            referance = (20 * hp) / max_hp;
            referance = 5 * referance ;
           } 
        else
            referance = (hp * 100) / max_hp  ;
        
//   加入误差值        
        diff = 51 - skill/2 ;
        diff = random(diff);
 
        if(random(2)==1)
          { der = "负" ; 
            referance -= diff ; 
           }
        else
          {
            der = "正" ;
            referance += diff ;
           } 
           
        if( referance > 100 ) 
           { 
               diff = diff - ( referance - 100 ) ;
               referance = 100 ;
            }
        if( referance < 0 )
           {
               diff = diff - ( 0 - referance ) ;
               referance = 0 ;  
           }
        if(wizardp(this_player()))
           write( sprintf("误差约为%s %d %% \n",der,diff) ) ;
 
        if( dest != this_player())
          {
            tell_object(dest,
                sprintf("%s绕著你晃了一圈, 嘴里不知道嘀咕些什麽东西。\n",
                   this_player()->query("c_name"))
                   );
           }
        else
            return notify_fail("要知道自己的状况, 打 Score 就好啦 !!\n") ;          
 
        write( sprintf( "%s现在的体力约剩下%d %% , 目前的身体状况 %s \n"
                        "正在作用中的针灸效果: %s。\n"
                ,dest->query("c_name"),referance,cond_str,acup_str));
        return 1;
}
 
 

