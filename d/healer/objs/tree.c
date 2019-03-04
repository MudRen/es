#include <mudlib.h>

inherit OBJECT;

void create()
{
   //  以下四项均为外形的描述， realname 才是成功的辨识後传回的名字     
        
	set_name("Standard Plant","标准的不明植物");     
	add( "id" , ({ "plant","tree","ivy" }) );        
	set_short("Standard Plant","标准的不明植物");    
	set_long(".." , "名称属性形状不明的植物。\n");   
        
        set("c_realname","黄大美女");         // 玩家辨认成功传回的名字
        set("realname","beauty");
	
   	set("unit","株");                     // 株,棵,盆.随便用

   	set("weight", 50000);                 // 只要保证玩家搬不动就好了

   	set("value", ({0, "silver"}) );       // 野生的树当然不值钱啊
      
        set("herb_file","NULL") ;             //提炼出来的东东的完整档名
        set("herb_path","/d/healer/plant/");   //提炼出来的东东的目录
                                              //记得用完整目录
                                              //default 是 /d/healer/plant
                                                
        set("skill_require",0) ;              //要成功辨识这种植物所须之技能
        set("purified",0);                    //是否被别人捷足先登,0为否,1为是
       
        set("plant_type",0);                  //

}
