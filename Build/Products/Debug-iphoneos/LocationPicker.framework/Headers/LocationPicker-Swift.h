// Generated by Apple Swift version 2.2 (swiftlang-703.0.18.8 clang-703.0.31)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if defined(__has_include) && __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
# if defined(__has_feature) && __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) SWIFT_ENUM(_type, _name)
# endif
#endif
#if defined(__has_feature) && __has_feature(modules)
@import ObjectiveC;
@import MapKit;
@import CoreLocation;
@import UIKit;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
@class CLLocation;
@class CLPlacemark;

SWIFT_CLASS("_TtC14LocationPicker8Location")
@interface Location : NSObject
@property (nonatomic, readonly, copy) NSString * _Nullable name;
@property (nonatomic, readonly, strong) CLLocation * _Nonnull location;
@property (nonatomic, readonly, strong) CLPlacemark * _Nonnull placemark;
@property (nonatomic, readonly, copy) NSString * _Nonnull address;
- (nonnull instancetype)initWithName:(NSString * _Nullable)name location:(CLLocation * _Nullable)location placemark:(CLPlacemark * _Nonnull)placemark OBJC_DESIGNATED_INITIALIZER;
@end


@interface Location (SWIFT_EXTENSION(LocationPicker))
@end


@interface Location (SWIFT_EXTENSION(LocationPicker)) <MKAnnotation>
@property (nonatomic, readonly) CLLocationCoordinate2D coordinate;
@property (nonatomic, readonly, copy) NSString * _Nullable title;
@end

@class UIColor;
@class NSBundle;
@class NSCoder;

SWIFT_CLASS("_TtC14LocationPicker28LocationPickerViewController")
@interface LocationPickerViewController : UIViewController
@property (nonatomic, copy) void (^ _Nullable completion)(Location * _Nullable);
@property (nonatomic) CLLocationDistance resultRegionDistance;

/// default: true
@property (nonatomic) BOOL showCurrentLocationButton;

/// default: true
@property (nonatomic) BOOL showCurrentLocationInitially;

/// see region property of MKLocalSearchRequest default: false
@property (nonatomic) BOOL useCurrentLocationAsHint;

/// default: "Search or enter an address"
@property (nonatomic, copy) NSString * _Nonnull searchBarPlaceholder;

/// default: "Search History"
@property (nonatomic, copy) NSString * _Nonnull searchHistoryLabel;

/// default: "Select"
@property (nonatomic, copy) NSString * _Nonnull selectButtonTitle;
@property (nonatomic, strong) UIColor * _Nonnull currentLocationButtonBackground;

/// default: .Minimal
@property (nonatomic) UISearchBarStyle searchBarStyle;
@property (nonatomic) MKMapType mapType;
@property (nonatomic, strong) Location * _Nullable location;
- (void)loadView;
- (void)viewDidLoad;
- (void)viewDidLayoutSubviews;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end


@interface LocationPickerViewController (SWIFT_EXTENSION(LocationPicker))
@end

@class CLLocationManager;

@interface LocationPickerViewController (SWIFT_EXTENSION(LocationPicker)) <CLLocationManagerDelegate>
- (void)locationManager:(CLLocationManager * _Nonnull)manager didUpdateLocations:(NSArray<CLLocation *> * _Nonnull)locations;
@end

@class UISearchBar;

@interface LocationPickerViewController (SWIFT_EXTENSION(LocationPicker)) <UISearchBarDelegate, UIBarPositioningDelegate>
- (void)searchBarTextDidBeginEditing:(UISearchBar * _Nonnull)searchBar;
- (void)searchBar:(UISearchBar * _Nonnull)searchBar textDidChange:(NSString * _Nonnull)searchText;
@end

@class MKMapView;
@class MKAnnotationView;
@class UIControl;

@interface LocationPickerViewController (SWIFT_EXTENSION(LocationPicker)) <MKMapViewDelegate>
- (MKAnnotationView * _Nullable)mapView:(MKMapView * _Nonnull)mapView viewForAnnotation:(id <MKAnnotation> _Nonnull)annotation;
- (void)mapView:(MKMapView * _Nonnull)mapView annotationView:(MKAnnotationView * _Nonnull)view calloutAccessoryControlTapped:(UIControl * _Nonnull)control;
- (void)mapView:(MKMapView * _Nonnull)mapView didAddAnnotationViews:(NSArray<MKAnnotationView *> * _Nonnull)views;
@end

@class UISearchController;

@interface LocationPickerViewController (SWIFT_EXTENSION(LocationPicker)) <UISearchResultsUpdating>
- (void)updateSearchResultsForSearchController:(UISearchController * _Nonnull)searchController;
@end

#pragma clang diagnostic pop
