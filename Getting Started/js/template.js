var myApp = angular.module('TabsApp', []);

myApp.controller('TabsCtrl', ['$scope', function ($scope) {
    $scope.tabs = [{
            title: 'monster',
            url: '../template/monster.html'
        }, {
            title: 'Two',
            url: 'two.tpl.html'
        }, {
            title: 'Three',
            url: 'three.tpl.html'
        }, {
            title: 'Four',
            url: 'four.tpl.html'
    }];

    $scope.currentTab = '../template/monster.html';

    $scope.onClickTab = function (tab) {
        $scope.currentTab = tab.url;
    }
    
    $scope.isActiveTab = function(tabUrl) {
        return tabUrl == $scope.currentTab;
    }
}]);

myApp.run(function($templateCache){
    $templateCache.put('../template/monster.html','This is the content of the template');
    
});
