---
layout: default
title: 游戏策划和设计
---

楔子(Setting)：很久很久以前，巨龙突然出现，它会分裂，带来灾难，带走公主。勇者达拉崩吧带上最好的地雷枪，翻过最高的山，拯救公主。

玩法(Gameplay)：玩家射死巨龙，杀的越多越好。玩家被杀，任务失败。玩家可使用键盘左右键移动躲避巨龙，用鼠标发出地雷。 

人设与道具（Game Sprites）：

Player：达拉崩吧。有很弱的生命值，不可以抵抗多次撞击。可以360旋转，连续无限量向前射击。

Boss: 红巨龙"血量极厚
      
      绿巨龙"体积极大

      蓝巨龙"普通巨龙

      黄巨龙"最强巨龙
…
+----------------------------------------------------------+  
| Player：达拉崩吧                                          |  
+----------------------------------------------------------+
| ![](https://wx3.sinaimg.cn/mw690/a093d017ly1fw18fb9elsj204m04m74w.jpg)
                                                           |
+--------------+-------------------------------------------+
|合作 子弹      | events：Set angel toward(Mouse.X,Mouse.Y) |

|              | Spawn Buttle on Layer 1                   |

|              | On collision with Buttle:                 |

|              | Spawn Exposion on Layer 1                 |

|              | Subtract 1 from Health                    |

|              | Health<=0:                                |

|              | Spawn Exposion on Layer 1                 |

|              | Destory                                   |

+--------------+-------------------------------------------+
|              |                   |
+----------------------------------------------------------+  
| BOSS：红龙                                              | 

+----------------------------------------------------------+
| ![](https://wx1.sinaimg.cn/mw690/a093d017ly1fw18fb6iu2j205808z0u9.jpg)
                                                           |
+--------------+-------------------------------------------+
|合作 蓝龙     | Subtract 1 from Health                     |

|     绿龙     | Is outside layout:                         |

|     黑龙     | Set angel to ramdon(360) degree            |

|              | Health<=0:                                |

|              | Subtract 1 from Health                    |

|              | Health<=0:                                |

|              | Spawn Exposion on Layer 1                 |

|              | Destory                                   |

+--------------+-------------------------------------------+
| BOSS：蓝龙                                              | 
 
+----------------------------------------------------------+
| ![](https://wx2.sinaimg.cn/mw690/a093d017ly1fw18fb8bw0j206805o401.jpg)
                                                           |
+--------------+-------------------------------------------+
|合作 红龙     | Subtract 1 from Health                     |

|     绿龙     | Is outside layout:                         |

|     黑龙     | Set angel to ramdon(360) degree            |

|              | Health<=0:                                |

|              | Subtract 1 from Health                    |

|              | Health<=0:                                |

|              | Spawn Exposion on Layer 1                 |

|              | Destory                                   |

+--------------+-------------------------------------------+
| BOSS：绿龙                                              | 
 
+----------------------------------------------------------+
| ![](https://wx1.sinaimg.cn/mw690/a093d017ly1fw18fb72nvj206c07tq5r.jpg)
                                                           |
+--------------+-------------------------------------------+
|合作 红龙     | Subtract 1 from Health                     |

|     蓝龙     | Is outside layout:                         |

|     黑龙     | Set angel to ramdon(360) degree            |

|              | Health<=0:                                |

|              | Subtract 1 from Health                    |

|              | Health<=0:                                |

|              | Spawn Exposion on Layer 1                 |

|              | Destory                                   |

+--------------+-------------------------------------------+
| BOSS：黑龙                                              | 
 
+----------------------------------------------------------+
| ![](https://wx4.sinaimg.cn/mw690/a093d017ly1fw18fb6q4fj203u04t3zc.jpg)
                                                           |
+--------------+-------------------------------------------+
|合作 红龙     | Subtract 1 from Health                     |

|     蓝龙     | Is outside layout:                         |

|     绿龙     | Set angel to ramdon(360) degree            |

|              | Health<=0:                                |

|              | Subtract 1 from Health                    |

|              | Health<=0:                                |

|              | Spawn Exposion on Layer 1                 |

|              | Destory                                   |

+--------------+-------------------------------------------+
| Buttle                                                   | 
 
+----------------------------------------------------------+
| ![](https://wx1.sinaimg.cn/mw690/a093d017ly1fw18u9bc3uj200p00c0hf.jpg)
                                                           |
+--------------+-------------------------------------------+
|合作 达拉崩吧  | On collision with BOSS:                    |

|              | Destory                                   |

+--------------+-------------------------------------------+
|Explsion                                                  | 
 
+----------------------------------------------------------+
| ![](https://wx4.sinaimg.cn/mw690/a093d017ly1fw18u9cocjj203a02ta9z.jpg)
                                                           |
+--------------+-------------------------------------------+
|合作 达拉崩吧  | Be spawned                                |

|              | Destory                                   |

+--------------+-------------------------------------------+

游戏预览：

![](https://raw.githubusercontent.com/xlcbingo1999/xlc-homework/gh-pages/images/游戏2.gif)


![](https://raw.githubusercontent.com/xlcbingo1999/xlc-homework/gh-pages/images/游戏3.gif)