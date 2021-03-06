#include <mudlib.h>

inherit OBJECT;
int in_use;

void init()
{
	add_action( "drink_wine", "drink" );
}

void create(){

	set_name("angel kiss","天使之吻");
        add("id",({"wine","kiss","angel kiss"}) );  
	set_short("天使之吻");
	set_long(@C_LONG
天使之吻是一杯被天使祝福过的酒,它其中的红色光泽散发出一股神秘而迷人的幽香 
它的来源,相传有一个美丽而哀怨的吉普赛女郎的故事,可以用以预测爱情. 而此地的 
天使之吻,是由天使调制的,听说喝了(drink)这杯酒(wine)後,将带给你无比的幸运...
C_LONG
                 );
        set("value" , ({10,"silver"}) );
        set("weight",10);
	set("unit","杯");
}

int drink_wine(string arg)
{
        if( arg != "wine") return 0;
        if (!in_use)
       {  
        in_use =1;
        
	set("prevent_drop",1); 
        set_short("天使之吻正发挥效用中"); 

	write( 
"你喝下了这杯天使之吻，一股幸福快乐的感觉从你的心中升起，你觉得自己好幸运 \n"
	);
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"喝下了一杯天使之吻，一群白色的天使围绕在他的身旁。\n",
		this_player() );
 
	this_player()->set_temp("extra_db",20);
	call_out("restore",60,this_player());
	return 1;
        }
}

void restore(object player){

	tell_object(player, 
		"围绕在你身旁的天使慢慢地飞走了...\n");
	this_player()->set_temp("extra_db",0);
        remove(); 
}
