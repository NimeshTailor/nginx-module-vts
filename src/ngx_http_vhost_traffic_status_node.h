
/*
 * Copyright (C) YoungJoo Kim (vozlt)
 */


#ifndef _NGX_HTTP_VTS_NODE_H_INCLUDED_
#define _NGX_HTTP_VTS_NODE_H_INCLUDED_


typedef struct {
    unsigned                     type;        /* unsigned type:5 */
    ngx_msec_t                   rtms;
} ngx_http_vhost_traffic_status_node_upstream_t;


typedef struct {
    u_char                                           color;
    ngx_atomic_t                                     stat_request_counter;
    ngx_atomic_t                                     stat_in_bytes;
    ngx_atomic_t                                     stat_out_bytes;
    ngx_atomic_t                                     stat_1xx_counter;
    ngx_atomic_t                                     stat_2xx_counter;
    ngx_atomic_t                                     stat_3xx_counter;
    ngx_atomic_t                                     stat_4xx_counter;
    ngx_atomic_t                                     stat_5xx_counter;

    ngx_msec_t                                       stat_request_time;

    /* deals with the overflow of variables */
    ngx_atomic_t                                     stat_request_counter_oc;
    ngx_atomic_t                                     stat_in_bytes_oc;
    ngx_atomic_t                                     stat_out_bytes_oc;
    ngx_atomic_t                                     stat_1xx_counter_oc;
    ngx_atomic_t                                     stat_2xx_counter_oc;
    ngx_atomic_t                                     stat_3xx_counter_oc;
    ngx_atomic_t                                     stat_4xx_counter_oc;
    ngx_atomic_t                                     stat_5xx_counter_oc;

#if (NGX_HTTP_CACHE)
    ngx_atomic_t                                     stat_cache_max_size;
    ngx_atomic_t                                     stat_cache_used_size;
    ngx_atomic_t                                     stat_cache_miss_counter;
    ngx_atomic_t                                     stat_cache_bypass_counter;
    ngx_atomic_t                                     stat_cache_expired_counter;
    ngx_atomic_t                                     stat_cache_stale_counter;
    ngx_atomic_t                                     stat_cache_updating_counter;
    ngx_atomic_t                                     stat_cache_revalidated_counter;
    ngx_atomic_t                                     stat_cache_hit_counter;
    ngx_atomic_t                                     stat_cache_scarce_counter;

    /* deals with the overflow of variables */
    ngx_atomic_t                                     stat_cache_miss_counter_oc;
    ngx_atomic_t                                     stat_cache_bypass_counter_oc;
    ngx_atomic_t                                     stat_cache_expired_counter_oc;
    ngx_atomic_t                                     stat_cache_stale_counter_oc;
    ngx_atomic_t                                     stat_cache_updating_counter_oc;
    ngx_atomic_t                                     stat_cache_revalidated_counter_oc;
    ngx_atomic_t                                     stat_cache_hit_counter_oc;
    ngx_atomic_t                                     stat_cache_scarce_counter_oc;
#endif

    ngx_http_vhost_traffic_status_node_upstream_t    stat_upstream;
    u_short                                          len;
    u_char                                           data[1];
} ngx_http_vhost_traffic_status_node_t;


ngx_int_t ngx_http_vhost_traffic_status_node_generate_key(ngx_pool_t *pool,
    ngx_str_t *buf, ngx_str_t *dst, unsigned type);
ngx_int_t ngx_http_vhost_traffic_status_node_position_key(ngx_str_t *buf,
    size_t pos);

ngx_rbtree_node_t *ngx_http_vhost_traffic_status_node_lookup(
    ngx_rbtree_t *rbtree, ngx_str_t *key, uint32_t hash);
void ngx_http_vhost_traffic_status_node_zero(
    ngx_http_vhost_traffic_status_node_t *vtsn);
void ngx_http_vhost_traffic_status_node_init(ngx_http_request_t *r,
    ngx_http_vhost_traffic_status_node_t *vtsn);
void ngx_http_vhost_traffic_status_node_set(ngx_http_request_t *r,
    ngx_http_vhost_traffic_status_node_t *vtsn);

void ngx_http_vhost_traffic_status_find_name(ngx_http_request_t *r,
    ngx_str_t *buf);
ngx_rbtree_node_t *ngx_http_vhost_traffic_status_find_node(ngx_http_request_t *r,
    ngx_str_t *key, unsigned type, uint32_t key_hash);

ngx_int_t ngx_http_vhost_traffic_status_node_member_cmp(ngx_str_t *member, const char *name);
ngx_atomic_uint_t ngx_http_vhost_traffic_status_node_member(ngx_http_vhost_traffic_status_node_t *vtsn,
    ngx_str_t *member);
ngx_int_t ngx_http_vhost_traffic_status_node_variable(ngx_http_request_t *r,
    ngx_http_variable_value_t *v, uintptr_t data);


#endif /* _NGX_HTTP_VTS_NODE_H_INCLUDED_ */

/* vi:set ft=c ts=4 sw=4 et fdm=marker: */