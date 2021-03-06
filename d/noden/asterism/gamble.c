//   This is std gamble lib for every thing that do anything to
//   gambling               indra@Eastern_Story 95.3.1

//   玩家不能同时上两个赌桌

int check_gamble(object obj)
{
   if(!(obj->query_temp("gambling")) )
      return 0 ;
   else    
      return 1 ;
} 

// 处理下注的动作, 在呼叫前要先将钱的种类整理成单一货币

int check_bet(int number,object player,int bet_time_flag)
{
   int old_bet ;
   if(!(number)||!(player)||!bet_time_flag)
      return 0 ;

   if( !(old_bet = player->query_temp("gambling/bet") ) )
       old_bet = 0 ;
         
   player->set_temp("gambling/bet",old_bet+number);
   return 1;
}
// 做设定玩哪个牌局的动作

int do_play_game(object player,string name,string play_msg,string play_msg1)
{
    player->set_temp("gambling/"+name) ;
    
    tell_object(player,sprintf("在短短的思考之後,你决定去玩%s。\n",cname) ) ;

    tell_room( environment(),play_msg1,player ) ;
                
    return 1;

}
//  洗牌的函式,须传入用具的型别,及重复的副数(因可能玩家太多,要用超过一副)

int *wash_cards(mapping card_style,int multi)
{
    int i,j , style_no , member_no , total_no , *cards_li,temp ;
    string *style_name ;
    
    total_no = 0 ;
    style_name = key(card_style) ;
    style_no = sizeof(style_name) ;
    cards_li = ({ }) ;
    
    if(!(multi)||(multi<1)) multi = 1 ;
      
    for(i=0;i<style_no;i++)    
       {
         member_no = sizeof(card_style[style_name[i]]) ;
         total_no = ( total_no + member_no ) * multi  ;        
        }  
    
    for(i=0;i<total_no;i++)
       {
         temp = random(total_no) ;
         
         for(j=0;j < i+1;j++)
            {
              if(j == i)
                { 
                  cards_li[i] = temp ; break ;
                 }
              if(temp==cards_li[j])
                {
                  --i ; break ;          
                 }
             }         
        }  
    return cards_li ;          
}


